#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Process ID (PID): %d\n", getpid());
    printf("Process is running / entering sleep loop...\n");

    // Infinite loop with sleep to easily observe Sleeping and Running states
    while (1) {
        sleep(2); // Process goes to sleep for 2 seconds repeatedly
    }

    return 0;
}
/*
output:
    PID STAT COMMAND
  40488 S+   question19

    PID STAT COMMAND
  40488 T    question19


*/
