#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd;
    struct flock lock;

    // 1. Open or create the test file
    fd = open("mandatory_test.txt", O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // 2. Configure the flock structure
    // Change l_type to F_RDLCK for a Read Lock, or F_WRLCK for a Write Lock
    lock.l_type = F_WRLCK;     // Set to F_WRLCK (Write Lock) or F_RDLCK (Read Lock)
    lock.l_whence = SEEK_SET;  // Beginning of file
    lock.l_start = 0;          // Offset 0
    lock.l_len = 0;            // 0 means lock the entire file

    printf("Attempting to apply lock...\n");

    // 3. Apply the lock using F_SETLKW (Wait until lock is acquired)
    if (fcntl(fd, F_SETLKW, &lock) < 0) {
        perror("Locking failed");
        close(fd);
        return 1;
    }

    printf("Lock successfully applied!\n");
    printf("File is locked. Keep this program running...\n");
    printf("Press [Enter] to release the lock and exit: ");
    
    getchar(); // Pause execution so you can test access from another terminal

    // 4. Release the lock before exiting
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    
    close(fd);
    printf("Lock released. Program terminated.\n");
    return 0;
}
/*
output:
Attempting to apply lock...
Lock successfully applied!
File is locked. Keep this program running...
Press [Enter] to release the lock and exit: 
Lock released. Program terminated.



*/
