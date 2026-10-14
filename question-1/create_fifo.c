#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Method 1: Using mkfifo library function
    int status1 = mkfifo("my_fifo_mkfifo", 0666);
    if (status1 == 0) {
        printf("FIFO created using mkfifo successfully.\n");
    } else {
        perror("mkfifo error");
    }

    // Method 2: Using mknod system call
    // S_IFIFO indicates a FIFO file type, 0666 grants read/write permissions
    int status2 = mknod("my_fifo_mknod", S_IFIFO | 0666, 0);
    if (status2 == 0) {
        printf("FIFO created using mknod successfully.\n");
    } else {
        perror("mknod error");
    }

    return 0;
}
