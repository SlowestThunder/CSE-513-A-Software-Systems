#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    fd_set readfds;
    struct timeval tv;

    // 1. Setup the file descriptor set for STDIN (fd 0)
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    // 2. Set timeout to 10 seconds
    tv.tv_sec = 10;
    tv.tv_usec = 0;

    printf("Waiting for input (10 seconds timeout)...\n");

    // 3. Wait using select()
    int ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);

    // 4. Check results
    if (ret < 0) {
        perror("select error");
    } 
    else if (ret == 0) {
        printf("\nTimeout! No data entered within 10 seconds.\n");
    } 
    else {
        // Data is ready
        char buf[100];
        int n = read(STDIN_FILENO, buf, sizeof(buf) - 1);
        if (n > 0) {
            buf[n] = '\0';
            printf("\nData received: %s", buf);
        }
    }

    return 0;
}
/*
output:
Waiting for input (10 seconds timeout)...
Hello, my dear friend

Data received: Hello, my dear friend



*/
