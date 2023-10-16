#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

int compare_strings(const void *a, const void *b) {
    return strlen(*(char **)b) - strlen(*(char **)a);
}

int main() {
    char input[MAX_LINES][MAX_LINE_LENGTH];
    char *lines[MAX_LINES];
    int line_count = 0;

   

    while (line_count < MAX_LINES && fgets(input[line_count], MAX_LINE_LENGTH, stdin) != NULL) {
        input[line_count][strcspn(input[line_count], "\n")] = 0;
        lines[line_count] = input[line_count];
        line_count++;
    }

    qsort(lines, line_count, sizeof(char *), compare_strings);

    
    for (int i = 0; i < line_count; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}

