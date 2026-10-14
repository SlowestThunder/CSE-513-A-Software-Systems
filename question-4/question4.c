#include <stdio.h>
#include <fcntl.h>   // Required for open() and O_ flags
#include <unistd.h>  // Required for close()
#include <errno.h>   // Required to inspect system errors

int main() {
    int fd;

    // PART 1: Open an existing file in Read-Write mode (O_RDWR)
    printf("--- Test 1: Opening file with O_RDWR ---\n");
    fd = open("test_file.txt", O_RDWR);

    if (fd < 0) {
        perror("Error opening file with O_RDWR");
    } else {
        printf("File opened successfully in Read-Write mode! File Descriptor: %d\n", fd);
        close(fd); // Always close the file descriptor after use
    }

    printf("\n--- Test 2: Opening file with O_CREAT | O_EXCL ---\n");
    // PART 2: Try opening/creating with O_CREAT and O_EXCL flags
    // O_EXCL ensures atomic file creation; if the file already exists, it MUST fail.
    fd = open("test_file.txt", O_RDWR | O_CREAT | O_EXCL, 0666);

    if (fd < 0) {
        // Expected behavior because test_file.txt already exists from Question 3
        perror("Error with O_EXCL flag");
    } else {
        printf("File created successfully with O_EXCL! File Descriptor: %d\n", fd);
        close(fd);
    }

    return 0;
}
/*
output:
--- Test 1: Opening file with O_RDWR ---
Error opening file with O_RDWR: No such file or directory

--- Test 2: Opening file with O_CREAT | O_EXCL ---
File created successfully with O_EXCL! File Descriptor: 3


*/
