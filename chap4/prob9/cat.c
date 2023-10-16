#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;
    int line_number = 1; 

    if (argc < 2) {
        return 1;
    }

    int print_line_numbers = 0;


    if (argc > 2 && strcmp(argv[1], "-n") == 0) {
        print_line_numbers = 1;
        argv++;
        argc--;
    }

    for (int i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");

        if (fp == NULL) {
            continue;
        }

        if (print_line_numbers) {
            printf("%d: ", line_number);
            line_number++;
        }

        c = getc(fp);
        while (c != EOF) {
            putc(c, stdout);

            if (c == '\n') {
                if (i < argc - 1) {
                    if (print_line_numbers) {
                        printf("\n%d: ", line_number);
                        line_number++;
                    }
                }
            }

            c = getc(fp);
        }

        fclose(fp);
    }

    return 0;
}

