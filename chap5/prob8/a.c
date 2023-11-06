#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1000
#define MAX_LENGTH 1000

int main(int argc, char *argv[]) {
    FILE *file;
    char lines[MAX_LINES][MAX_LENGTH];
    int lineNumber = 0;

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

    printf("You can select a line from 1 to %d\n", totalLines);
    printf("Enter the line number you want to print: ");
    scanf("%d", &lineNumber);

    if (lineNumber > totalLines || lineNumber <= 0) {
        printf("Invalid line number entered.\n");
    } else {
        printf("Selected line: %s", lines[lineNumber - 1]);
    }

    fclose(file);

    return 0;
}

