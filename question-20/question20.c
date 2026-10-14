#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    printf("Before fork(): Common process (PID: %d)\n", getpid());

    // 1. Create a child process using fork()
    pid = fork();

    // 2. Check if fork failed
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } 
    // 3. Child process branch
    else if (pid == 0) {
        printf("\n--> [CHILD PROCESS]\n");
        printf("    My PID is: %d\n", getpid());
        printf("    My Parent's PID (PPID) is: %d\n", getppid());
        printf("    fork() returned: %d (indicates child)\n", pid);
    } 
    // 4. Parent process branch
    else {
        printf("\n--> [PARENT PROCESS]\n");
        printf("    My PID is: %d\n", getpid());
        printf("    My Child's PID is: %d\n", pid);
        printf("    My Parent's PID (PPID) is: %d\n", getppid());
    }

    return 0;
}
/*
output:
Before fork(): Common process (PID: 40847)

--> [PARENT PROCESS]
    My PID is: 40847
    My Child's PID is: 40848
    My Parent's PID (PPID) is: 9262

--> [CHILD PROCESS]
    My PID is: 40848
    My Parent's PID (PPID) is: 40847
    fork() returned: 0 (indicates child)



*/
