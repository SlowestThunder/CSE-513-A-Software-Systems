#include <stdio.h>
#include <fcntl.h>   // For open(), fcntl()
#include <unistd.h>  // For dup(), dup2(), write(), close()

int main() {
    // 1. Open a file in write-only mode
    int fd1 = open("file_dup.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd1 < 0) {
        perror("Error opening file");
        return 1;
    }

    // 2. Duplicate file descriptor using dup()
    int fd2 = dup(fd1);
    printf("Original FD (fd1): %d\n", fd1);
    printf("Duplicated FD (fd2): %d\n", fd2);

    // 3. Write data using the original file descriptor
    write(fd1, "Hello ", 6);

    // 4. Write data using the duplicated file descriptor
    // Because they share the same file table entry, writes continue sequentially!
    write(fd2, "World!\n", 7);

    // Close both descriptors
    close(fd1);
    close(fd2);

    printf("Data written successfully. Check file contents!\n");
    return 0;
}
/*
output:
Original FD (fd1): 3
Duplicated FD (fd2): 4
Data written successfully. Check file contents!

*/
