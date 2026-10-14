#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open or create ticket.txt with write, create, and truncate permissions
    int fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // Write initial ticket number "100" into the file
    write(fd, "100", 3);
    
    close(fd);
    printf("Ticket file initialized with starting number: 100\n");
    return 0;
}
