#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define RECORD_SIZE 60
#define TOTAL_RECORDS 3

int main() {
    int fd;
    struct flock lock;
    int choice, rec_num;
    char buffer[RECORD_SIZE];

    // 1. Open or create the file with 3 initial records
    fd = open("records.txt", O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // Initialize file with 3 records if empty
    char init_data[RECORD_SIZE];
    snprintf(init_data, RECORD_SIZE, "%-58s\n", "Default Record Data");
    for (int i = 0; i < TOTAL_RECORDS; i++) {
        write(fd, init_data, RECORD_SIZE);
    }

    printf("--- Record Locking Menu ---\n");
    printf("1. Apply Read Lock (Read Record)\n");
    printf("2. Apply Write Lock (Modify Record)\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter record number (0, 1, or 2): ");
    scanf("%d", &rec_num);

    if (rec_num < 0 || rec_num >= TOTAL_RECORDS) {
        printf("Invalid record number! Choose between 0 and 2.\n");
        close(fd);
        return 1;
    }

    // 2. Configure flock for the specific record offset
    lock.l_whence = SEEK_SET;
    lock.l_start = rec_num * RECORD_SIZE; // Target exact record position
    lock.l_len = RECORD_SIZE;             // Lock only this single record's size

    if (choice == 1) {
        lock.l_type = F_RDLCK; // Shared Read Lock
        printf("Trying to acquire Read Lock on Record %d...\n", rec_num);
    } else {
        lock.l_type = F_WRLCK; // Exclusive Write Lock
        printf("Trying to acquire Write Lock on Record %d...\n", rec_num);
    }

    // 3. Apply the lock (F_SETLKW waits if locked by another process)
    if (fcntl(fd, F_SETLKW, &lock) < 0) {
        perror("Lock failed");
        close(fd);
        return 1;
    }

    printf("Lock acquired successfully on Record %d!\n", rec_num);

    // 4. Perform read or write operation based on lock type
    off_t offset = rec_num * RECORD_SIZE;
    lseek(fd, offset, SEEK_SET);

    if (lock.l_type == F_RDLCK) {
        // Read record content
        read(fd, buffer, RECORD_SIZE);
        buffer[RECORD_SIZE - 1] = '\0';
        printf("Content of Record %d: %s\n", rec_num, buffer);
    } else {
        // Modify record content
        printf("Enter new text (max 50 chars): ");
        char input[55];
        scanf("%50s", input);

        // Format safely to fit the record size without truncation warning
        snprintf(buffer, RECORD_SIZE, "%-58s\n", input);
        lseek(fd, offset, SEEK_SET);
        write(fd, buffer, RECORD_SIZE);
        printf("Record %d successfully updated!\n", rec_num);
    }

    // Keep program paused so you can test concurrent locking in another terminal
    printf("Press [Enter] to release lock and exit: ");
    getchar(); // Clear buffer newline
    getchar(); // Wait for Enter

    // 5. Unlock the record before exiting
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    printf("Lock released. Program exited.\n");
    return 0;
}



/*
output:
--- Record Locking Menu ---
1. Apply Read Lock (Read Record)
2. Apply Write Lock (Modify Record)
Enter choice (1 or 2): 2
Enter record number (0, 1, or 2): 1
Trying to acquire Write Lock on Record 1...
Lock acquired successfully on Record 1!
Enter new text (max 50 chars): Hello friend
Record 1 successfully updated!
Press [Enter] to release lock and exit: Lock released. Program exited.



*/
