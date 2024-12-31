//Write a C program to copy the contents of one file to another file.


#include <stdio.h>
#include <stdlib.h>

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "r");
    if (src == NULL) {
        perror("fopen (source)");
        return;
    }

    FILE *dest = fopen(destination, "w");
    if (dest == NULL) {
        perror("fopen (destination)");
        fclose(src);
        return;
    }

    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied from '%s' to '%s' successfully.\n", source, destination);

    fclose(src);
    fclose(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    copy_file(argv[1], argv[2]);

    return EXIT_SUCCESS;
}
