#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }

    FILE *source_file, *destination_file;
    char ch;

    source_file = fopen(argv[1], "r");
    if (source_file == NULL) {
        return 1;
    }

    destination_file = fopen(argv[2], "a");
    if (destination_file == NULL) {
        fclose(source_file);
        return 1;
    }

    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, destination_file);
    }


    fclose(source_file);
    fclose(destination_file);

    return 0;
}

