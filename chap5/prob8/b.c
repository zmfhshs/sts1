#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 1000

int main(int argc, char *argv[]) {
    FILE *file;
    char lines[MAX_LINES][MAX_LENGTH];
    char input[20];
    int lineStart = 0, lineEnd = 0;

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    int totalLines = 0;

    while (fgets(lines[totalLines], MAX_LENGTH, file) && totalLines < MAX_LINES) {
        totalLines++;
    }

    printf("Total lines in the file: %d\n", totalLines);

    if (totalLines == 0) {
        printf("The file is empty.\n");
        fclose(file);
        return 0;
    }

    printf("You can select lines from 1 to %d\n", totalLines);
    printf("Enter the line number(s) you want to print (e.g., '1,3' or '1-3'): ");
    scanf("%s", input);

    if (strstr(input, "-") != NULL) {
        // Range input detected (e.g., '1-3')
        sscanf(input, "%d-%d", &lineStart, &lineEnd);
    } else {
        // Single or comma-separated values (e.g., '1,3')
        sscanf(input, "%d,%d", &lineStart, &lineEnd);
    }

    if (lineStart > totalLines || lineStart <= 0 || lineEnd <= 0 || lineEnd > totalLines || lineStart > lineEnd) {
        printf("Invalid line number(s) entered.\n");
    } else {
        printf("Selected line(s):\n");
        for (int i = lineStart; i <= lineEnd; i++) {
            printf("%s", lines[i - 1]);
        }
    }

    fclose(file);

    return 0;
}

