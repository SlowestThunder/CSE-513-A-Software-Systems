#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

// Helper function to print policy names clearly
void print_policy(int policy) {
    switch(policy) {
        case SCHED_OTHER: 
            printf("SCHED_OTHER (Standard / Normal)\n"); 
            break;
        case SCHED_FIFO:  
            printf("SCHED_FIFO (Real-time First-In, First-Out)\n"); 
            break;
        case SCHED_RR:    
            printf("SCHED_RR (Real-time Round-Robin)\n"); 
            break;
        default:          
            printf("Unknown Policy\n");
    }
}

int main() {
    pid_t pid = 0; // 0 means the current calling process

    // 1. Get and print the current scheduling policy
    int current_policy = sched_getscheduler(pid);
    if (current_policy == -1) {
        perror("sched_getscheduler failed");
        return 1;
    }

    printf("Current Scheduling Policy: ");
    print_policy(current_policy);

    // 2. Setup scheduling parameters for real-time policy
    struct sched_param param;
    param.sched_priority = 10; // Set a valid real-time priority (between 1 and 99)

    // 3. Modify the scheduling policy to SCHED_FIFO
    printf("\nAttempting to change policy to SCHED_FIFO with priority 10...\n");
    
    if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler failed");
        printf("Note: Changing to a real-time policy requires root privileges (sudo).\n");
        return 1;
    }

    // 4. Verify the updated policy
    int new_policy = sched_getscheduler(pid);
    printf("Successfully modified! New Scheduling Policy: ");
    print_policy(new_policy);

    return 0;
}

/*
output:
Current Scheduling Policy: SCHED_OTHER (Standard / Normal)

Attempting to change policy to SCHED_FIFO with priority 10...
Successfully modified! New Scheduling Policy: SCHED_FIFO (Real-time First-In, First-Out)



*/
