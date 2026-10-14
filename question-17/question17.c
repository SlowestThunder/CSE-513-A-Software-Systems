#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // 1. Open the ticket file in Read-Write mode
    int fd = open("ticket.txt", O_RDWR);
    if (fd < 0) {
        perror("Error opening ticket file");
        return 1;
    }

    // 2. Configure flock structure for an exclusive Write Lock
    struct flock lock;
    lock.l_type = F_WRLCK;     // Exclusive write lock
    lock.l_whence = SEEK_SET;  // From beginning of file
    lock.l_start = 0;          // Offset 0
    lock.l_len = 0;            // 0 means lock the entire file

    printf("Waiting to acquire write lock for ticket booking...\n");

    // 3. Apply write lock using F_SETLKW (blocking wait if another process holds it)
    if (fcntl(fd, F_SETLKW, &lock) < 0) {
        perror("Locking failed");
        close(fd);
        return 1;
    }

    printf("Write lock acquired successfully!\n");

    // 4. Read the current ticket number from the file
    char buffer[10] = {0};
    lseek(fd, 0, SEEK_SET); // Ensure pointer is at the start
    read(fd, buffer, sizeof(buffer) - 1);
    int ticket_no = atoi(buffer);

    // 5. Increment the ticket number
    ticket_no++;

    // 6. Move file pointer back to the beginning to overwrite the old value
    lseek(fd, 0, SEEK_SET);

    // 7. Write the new incremented ticket number back to the file
    char out_buf[10];
    int len = snprintf(out_buf, sizeof(out_buf), "%d", ticket_no);
    write(fd, out_buf, len);

    printf(">>> TICKET BOOKED! New Ticket Number: %d <<<\n", ticket_no);

    // Pause briefly so you can test concurrent execution from another terminal
    printf("Press [Enter] to complete reservation and release lock: ");
    getchar();

    // 8. Release the lock before closing
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    printf("Lock released. Transaction complete.\n");
    return 0;
}
/*
output:
Waiting to acquire write lock for ticket booking...
Write lock acquired successfully!
>>> TICKET BOOKED! New Ticket Number: 101 <<<
Press [Enter] to complete reservation and release lock: 
Lock released. Transaction complete.

Waiting to acquire write lock for ticket booking...
Write lock acquired successfully!
>>> TICKET BOOKED! New Ticket Number: 102 <<<
Press [Enter] to complete reservation and release lock: 
Lock released. Transaction complete.


*/
