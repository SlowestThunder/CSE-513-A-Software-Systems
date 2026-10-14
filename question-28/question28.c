#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>

int main() {
    // Clear errno to accurately check for errors from getpriority
    errno = 0;
    
    // Get priority of the current process (PRIO_PROCESS, 0 means current PID)
    int nice_val = getpriority(PRIO_PROCESS, 0);

    if (nice_val == -1 && errno != 0) {
        perror("getpriority failed");
        return 1;
    }

    printf("--- Process Priority Info ---\n");
    printf("Process PID : %d\n", getpid());
    printf("Nice Value  : %d\n", nice_val);

    return 0;
}
/*
output:
--- Process Priority Info ---
Process PID : 44158
Nice Value  : 0

after changing:
--- Process Priority Info ---
Process PID : 44177
Nice Value  : 10





*/
