#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Sender process (PID: %d) is calling exec to run ./receiver with an argument...\n", getpid());

    // Pass the program name and the argument "Ravi", terminated by NULL
    execlp("./receiver", "./receiver", "Ravi", NULL);

    // If exec fails
    perror("exec failed");
    return 1;
}
