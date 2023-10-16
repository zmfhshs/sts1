#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

char lines[MAXLINE][MAXLINE]; 
int line_lengths[MAXLINE];     

void sort_lines(int line_count) {

    for (int i = 0; i < line_count - 1; i++) {
        for (int j = i + 1; j < line_count; j++) {
            if (line_lengths[i] > line_lengths[j]) {
                int temp_len = line_lengths[i];
                line_lengths[i] = line_lengths[j];
                line_lengths[j] = temp_len;
                
                char temp[MAXLINE];
                strcpy(temp, lines[i]);
                strcpy(lines[i], lines[j]);
                strcpy(lines[j], temp);
            }
        }
    }
}

int main() {
    int line_count = 0;
    int max_length = 0;
    int length;

    while (fgets(lines[line_count], MAXLINE, stdin) != NULL) {
        length = strlen(lines[line_count]);
        line_lengths[line_count] = length;

        if (length > max_length) {
            max_length = length;
        }

        line_count++;
    }

    sort_lines(line_count);

    for (int i = 0; i < line_count; i++) {
        printf("%s", lines[i]);
    }

    return 0;
}

