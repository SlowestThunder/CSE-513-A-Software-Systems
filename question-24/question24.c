#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pids[3];
    int status;

    // 1. Create three child processes using a loop
    for (int i = 0; i < 3; i++) {
        child_pids[i] = fork();

        if (child_pids[i] < 0) {
            perror("fork failed");
            return 1;
        } 
        else if (child_pids[i] == 0) {
            // --- Child Process Code ---
            printf("Child %d started with PID: %d\n", i + 1, getpid());
            sleep(2 * (i + 1)); // Sleep for different durations (2s, 4s, 6s)
            printf("Child %d (PID: %d) is now exiting.\n", i + 1, getpid());
            exit(i + 10); // Exit with a custom status code
        }
    }

    // --- Parent Process Code ---
    // Let's target a specific child—for example, the SECOND child (index 1)
    pid_t target_child = child_pids[1];
    printf("\nParent (PID: %d) is specifically waiting for Child 2 (PID: %d)...\n", getpid(), target_child);

    // 2. Use waitpid to wait for that exact child PID
    pid_t waited_pid = waitpid(target_child, &status, 0);

    if (waited_pid > 0) {
        if (WIFEXITED(status)) {
            printf("\n--> Parent: Target Child 2 (PID: %d) finished with exit status: %d\n", 
                   waited_pid, WEXITSTATUS(status));
        }
    }

    // 3. Clean up the remaining children so they don't become zombies
    for (int i = 0; i < 3; i++) {
        if (i != 1) { // Skip index 1 since we already waited for it
            waitpid(child_pids[i], NULL, 0);
        }
    }

    printf("Parent process finished cleaning up all children and is exiting.\n");
    return 0;
}
/*
output:
Child 1 started with PID: 42021
Child 2 started with PID: 42022

Parent (PID: 42020) is specifically waiting for Child 2 (PID: 42022)...
Child 3 started with PID: 42023
Child 1 (PID: 42021) is now exiting.
Child 2 (PID: 42022) is now exiting.

--> Parent: Target Child 2 (PID: 42022) finished with exit status: 11
Child 3 (PID: 42023) is now exiting.
Parent process finished cleaning up all children and is exiting.



*/
