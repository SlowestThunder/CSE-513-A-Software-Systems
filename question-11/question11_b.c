#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // 1. Open file in write-only mode
    int fd1 = open("file_dup2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd1 < 0) {
        perror("Error opening file");
        return 1;
    }

    // 2. Explicitly duplicate fd1 into descriptor number 7 using dup2()
    int fd2 = dup2(fd1, 7);
    printf("Original FD: %d, Target/Duplicated FD (forced to 7): %d\n", fd1, fd2);

    // 3. Write using both descriptors
    write(fd1, "Linux ", 6);
    write(fd2, "Programming!\n", 13);

    // 4. Close files
    close(fd1);
    close(fd2);

    printf("Done! Run: cat file_dup2.txt\n");
    return 0;
}
/*
output:
Original FD: 3, Target/Duplicated FD (forced to 7): 7
Done! Run: cat file_dup2.txt

*/
