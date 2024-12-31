//Write a C program to list all files and sub-directories in a directory.

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void list_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Contents of directory: %s\n", path);

    while ((entry = readdir(dp)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    list_files(argv[1]);

    return EXIT_SUCCESS;
}
