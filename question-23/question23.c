#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } 
    else if (pid == 0) {
        // --- Child Process ---
        printf("Child process started. My PID: %d, Parent PPID: %d\n", getpid(), getppid());
        
        // Sleep for 3 seconds to ensure the parent process exits first
        sleep(3);

        // After parent dies, check the parent PID again
        printf("Child is now orphaned! New Parent PID (adopted by systemd/init): %d\n", getppid());
    } 
    else {
        // --- Parent Process ---
        printf("Parent process (PID: %d) exiting immediately...\n", getpid());
        exit(0); // Parent terminates, leaving the child running
    }

    return 0;
}
/*
output:
Parent process (PID: 41852) exiting immediately...
Child process started. My PID: 41853, Parent PPID: 41852
Child is now orphaned! New Parent PID (adopted by systemd/init): 3919



*/
