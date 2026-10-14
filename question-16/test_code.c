#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("mandatory_test.txt", O_RDWR);
    if (fd < 0) {
        perror("Open failed");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Test program trying to acquire lock...\n");

    // Try to get a write lock using F_SETLKW (Wait for it)
    if (fcntl(fd, F_SETLKW, &lock) < 0) {
        perror("Lock failed");
    } else {
        printf("Successfully acquired lock!\n");
    }

    close(fd);
    return 0;
}
