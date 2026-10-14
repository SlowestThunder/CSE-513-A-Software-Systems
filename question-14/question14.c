#include <stdio.h>
#include <sys/stat.h> // For lstat() and file type macros

int main(int argc, char *argv[]) {
    // Check if filename argument is provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat s;

    // Use lstat() so that if the file is a symbolic link, 
    // it inspects the link itself rather than the target file.
    if (lstat(argv[1], &s) < 0) {
        perror("Error retrieving file status");
        return 1;
    }

    printf("File: %s\nType: ", argv[1]);

    // Check file type using standard macros on st_mode
    if (S_ISREG(s.st_mode)) {
        printf("Regular File\n");
    } else if (S_ISDIR(s.st_mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(s.st_mode)) {
        printf("Symbolic Link\n");
    } else if (S_ISCHR(s.st_mode)) {
        printf("Character Device File\n");
    } else if (S_ISBLK(s.st_mode)) {
        printf("Block Device File\n");
    } else if (S_ISFIFO(s.st_mode)) {
        printf("FIFO / Named Pipe\n");
    } else if (S_ISSOCK(s.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown Type\n");
    }

    return 0;
}
/*
output:
File: file1.txt
Type: Regular File

File: test
Type: Directory



*/
