#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LEN 100

void execute_command(char *cmd) {
    char *args[MAX_COMMANDS];
    int i = 0;

    char *token = strtok(cmd, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execvp(args[0], args);
        printf("Command execution failed.\n");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
    }
}

int main() {
    char input[MAX_COMMAND_LEN];
    while (1) {
        printf("[shell] ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            break;
        }

        char *commands[MAX_COMMANDS];
        int i = 0;

        char *token = strtok(input, ";");
        while (token != NULL) {
            commands[i++] = token;
            token = strtok(NULL, ";");
        }
        commands[i] = NULL;

        for (int j = 0; j < i; j++) {
            char *cmd = commands[j];

            if (strstr(cmd, "&") != NULL) {
                strtok(cmd, "&");
                execute_command(cmd);
            } else if (strstr(cmd, ">") != NULL) {
                char *parts[2];
                parts[0] = strtok(cmd, ">");
                parts[1] = strtok(NULL, ">");

                int fd = open(parts[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (fd < 0) {
                    printf("Failed to open output file.\n");
                    exit(EXIT_FAILURE);
                }
                dup2(fd, STDOUT_FILENO);
                close(fd);

                execute_command(parts[0]);
            } else if (strstr(cmd, "<") != NULL) {
                char *parts[2];
                parts[0] = strtok(cmd, "<");
                parts[1] = strtok(NULL, "<");

                int fd = open(parts[1], O_RDONLY);
                if (fd < 0) {
                    printf("Failed to open input file.\n");
                    exit(EXIT_FAILURE);
                }
                dup2(fd, STDIN_FILENO);
                close(fd);

                execute_command(parts[0]);
            } else {
                execute_command(cmd);
            }
        }
    }

    return 0;
}

