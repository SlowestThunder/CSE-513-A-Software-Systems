#include <stdio.h>
#include <unistd.h> // Header for read(), write(), STDIN_FILENO, STDOUT_FILENO

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Optional user prompt using write() system call
    write(1, "Enter text: ", 12);

    // read(file_descriptor, buffer, max_bytes)
    // Read up to BUFFER_SIZE bytes from STDIN (FD 0)
    bytes_read = read(0, buffer, sizeof(buffer));

    if (bytes_read < 0) {
        perror("Error reading from STDIN");
        return 1;
    }

    // Optional label output using write() system call
    write(1, "You entered: ", 13);

    // write(file_descriptor, buffer, bytes_to_write)
    // Write exactly the number of bytes read to STDOUT (FD 1)
    write(1, buffer, bytes_read);

    return 0;
}
/*
output:
Enter text: Hello,my dear friend
You entered: Hello,my dear friend
*/
