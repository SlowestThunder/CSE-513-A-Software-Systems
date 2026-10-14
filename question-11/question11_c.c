#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // 1. Open file in write-only mode
    int fd1 = open("file_fcntl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd1 < 0) {
        perror("Error opening file");
        return 1;
    }

    // 2. Duplicate fd1 using fcntl with F_DUPFD (minimum FD is set to 5)
    int fd2 = fcntl(fd1, F_DUPFD, 5);
    printf("Original FD: %d, Duplicated FD (>= 5): %d\n", fd1, fd2);

    // 3. Write using both descriptors
    write(fd1, "System ", 7);
    write(fd2, "Software!\n", 10);

    // 4. Close files
    close(fd1);
    close(fd2);

    printf("Done! Run: cat file_fcntl.txt\n");
    return 0;
}
/*
output:
Original FD: 3, Duplicated FD (>= 5): 5
Done! Run: cat file_fcntl.txt

*/
