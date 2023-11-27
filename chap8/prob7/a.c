#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_all_environment_values() {
    extern char **environ;
    char **current_env = environ;
    
    while (*current_env != NULL) {
        printf("%s\n", *current_env);
        current_env++;
    }
}

void print_environment_values(int argc, char *argv[]) {
    if (argc > 2) {
        for (int i = 2; i < argc; i++) {
            char *env_value = getenv(argv[i]);
            if (env_value != NULL) {
                printf("%s: %s\n", argv[i], env_value);
            } else {
                printf("No value found for environment variable '%s'.\n", argv[i]);
            }
        }
    } else {
        print_all_environment_values();
    }
}

void print_user_ids() {
    printf("My Realistic user ID: %d\n", getuid());
    printf("My Valid user ID: %d\n", geteuid());
}

void print_group_ids() {
    printf("My Realistic  group ID: %d\n", getgid());
    printf("My valid group ID: %d\n", getegid());
}

void print_process_id() {
    printf("My Process ID: %d\n", getpid());
}

void print_parent_process_id() {
    printf("My Parent process ID: %d\n", getppid());
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (argv[1][0] == '-') {
            switch (argv[1][1]) {
                case 'e':
                    print_environment_values(argc, argv);
                    break;
                case 'u':
                    print_user_ids();
                    break;
                case 'g':
                    print_group_ids();
                    break;
                case 'i':
                    print_process_id();
                    break;
                case 'p':
                    print_parent_process_id();
                    break;
                default:
                    printf("Invalid option.\n");
            }
        } else {
            printf("Incorrect option format.\n");
        }
    } else {
        printf("No option specified.\n");
    }
    return 0;
}

