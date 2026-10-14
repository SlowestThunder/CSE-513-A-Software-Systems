#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("\n[Receiver Program Started Successfully]\n");

    // Check if an argument was passed from the executor
    if (argc > 1) {
        printf("Received argument (name): %s\n", argv[1]);
    } else {
        printf("No arguments received.\n");
    }

    return 0;
}
/*
output:
Sender process (PID: 42690) is calling exec to run ./receiver with an argument...

[Receiver Program Started Successfully]
Received argument (name): Ravi
*/
