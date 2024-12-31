//Write a C program to merge the contents of two files into a third file.

#include <stdio.h>
#include <stdlib.h>

void merge_files(const char *file1, const char *file2, const char *output_file) {
    FILE *src1 = fopen(file1, "r");
    if (src1 == NULL) {
        perror("fopen (file1)");
        return;
    }

    FILE *src2 = fopen(file2, "r");
    if (src2 == NULL) {
        perror("fopen (file2)");
        fclose(src1);
        return;
    }

    FILE *dest = fopen(output_file, "w");
    if (dest == NULL) {
        perror("fopen (output_file)");
        fclose(src1);
        fclose(src2);
        return;
    }

    char ch;

    // Copy contents of the first file
    while ((ch = fgetc(src1)) != EOF) {
        fputc(ch, dest);
    }

    // Copy contents of the second file
    while ((ch = fgetc(src2)) != EOF) {
        fputc(ch, dest);
    }

    printf("Files '%s' and '%s' merged into '%s' successfully.\n", file1, file2, output_file);

    fclose(src1);
    fclose(src2);
    fclose(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file1> <file2> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    merge_files(argv[1], argv[2], argv[3]);

    return EXIT_SUCCESS;
}
