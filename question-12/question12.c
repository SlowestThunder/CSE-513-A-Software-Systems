#include <stdio.h>
#include <fcntl.h>   // For open(), fcntl(), F_GETFL, O_ACCMODE
#include <unistd.h>  // For close()

int main() {
    // 1. Open a file with Read-Write and Append modes
    int fd = open("test_mode.txt", O_RDWR | O_CREAT | O_APPEND, 0666);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // 2. Retrieve file status flags using fcntl with F_GETFL
    int flags = fcntl(fd, F_GETFL);
    if (flags < 0) {
        perror("fcntl F_GETFL error");
        close(fd);
        return 1;
    }

    // 3. Extract access mode using the O_ACCMODE bitmask
    int access_mode = flags & O_ACCMODE;

    printf("--- File Opening Mode Analysis ---\n");
    if (access_mode == O_RDONLY) {
        printf("File Opening Mode: Read-Only (O_RDONLY)\n");
    } else if (access_mode == O_WRONLY) {
        printf("File Opening Mode: Write-Only (O_WRONLY)\n");
    } else if (access_mode == O_RDWR) {
        printf("File Opening Mode: Read-Write (O_RDWR)\n");
    }

    // 4. Check for optional status flags (like O_APPEND)
    if (flags & O_APPEND) {
        printf("Additional Flag: O_APPEND is active\n");
    }

    // Clean up
    close(fd);
    return 0;
}
/*
output:
--- File Opening Mode Analysis ---
File Opening Mode: Read-Write (O_RDWR)
Additional Flag: O_APPEND is active

*/
