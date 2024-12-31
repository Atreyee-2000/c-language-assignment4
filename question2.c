//Write a C program to count the number of lines in a file.

#include <stdio.h>
#include <stdlib.h>

int count_lines_in_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return -1;
    }

    int count = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    fclose(file);
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int line_count = count_lines_in_file(argv[1]);
    if (line_count >= 0) {
        printf("Number of lines in file '%s': %d\n", argv[1], line_count);
    }

    return EXIT_SUCCESS;
}
