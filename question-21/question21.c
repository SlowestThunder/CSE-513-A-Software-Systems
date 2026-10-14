#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    // 1. Open the file BEFORE fork so parent and child share the file descriptor
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // 2. Create child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        close(fd);
        return 1;
    } 
    else if (pid == 0) {
        // --- Child Process ---
        char *child_msg = "This line is written by the CHILD process.\n";
        // Write multiple times to simulate concurrent load
        for (int i = 0; i < 3; i++) {
            write(fd, child_msg, strlen(child_msg));
            usleep(100); // Small delay to let them interleave
        }
    } 
    else {
        // --- Parent Process ---
        char *parent_msg = "This line is written by the PARENT process.\n";
        // Write multiple times
        for (int i = 0; i < 3; i++) {
            write(fd, parent_msg, strlen(parent_msg));
            usleep(100); // Small delay
        }
    }

    // Close file descriptor
    close(fd);
    return 0;
}
/*
output:
This line is written by the PARENT process.
This line is written by the CHILD process.
This line is written by the PARENT process.
This line is written by the CHILD process.
This line is written by the PARENT process.
This line is written by the CHILD process.


*/
