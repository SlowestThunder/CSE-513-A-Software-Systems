#include <stdio.h>
#include <fcntl.h>   // Required for creat() system call
#include <unistd.h>  // Required for close() system call

int main() {
    // creat(pathname, mode)
    // S_IRUSR | S_IWUSR gives Read and Write permissions to the file Owner (0600)
    int fd = creat("test_file.txt", S_IRUSR | S_IWUSR);

    if (fd < 0) {
        perror("Error creating file");
        return 1;
    }

    printf("File created successfully!\n");
    printf("File Descriptor Value: %d\n", fd);

    // Clean up by closing the file descriptor
    close(fd);

    return 0;
}
/*
output:
File created successfully!
File Descriptor Value: 3


-rw------- 1 ravi ravi 0 Sep 22 00:25 test_file.txt
*/
