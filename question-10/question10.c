#include <stdio.h>
#include <fcntl.h>   // For open(), O_RDWR, O_CREAT, O_TRUNC
#include <unistd.h>  // For write(), lseek(), close()

int main() {
    // 1. Open file in Read-Write mode, create if it doesn't exist
    int fd = open("test_lseek.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // 2. Write initial 10 bytes ("1234567890")
    write(fd, "1234567890", 10);

    // 3. Move the file pointer forward by 10 bytes relative to current position
    // lseek returns the new offset from the beginning of the file
    off_t offset = lseek(fd, 10, SEEK_CUR);

    // Part (a): Check and print the return value of lseek
    printf("a. Return value of lseek (new offset position): %ld bytes\n", (long)offset);

    // 4. Write another 10 bytes ("ABCDEFGHIJ")
    write(fd, "ABCDEFGHIJ", 10);

    close(fd);
    printf("Data written successfully!\n");

    return 0;
}
/*
output:

a).
Return value of lseek (new offset position): 20 bytes
Data written successfully!

b).
0000000   1   2   3   4   5   6   7   8   9   0  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   A   B   C   D   E   F   G   H   I   J
0000036
*/
