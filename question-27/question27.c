#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main() {
    int max_fifo, min_fifo;
    int max_rr, min_rr;

    // 1. Retrieve priorities for SCHED_FIFO (First-In, First-Out real-time policy)
    max_fifo = sched_get_priority_max(SCHED_FIFO);
    min_fifo = sched_get_priority_min(SCHED_FIFO);

    if (max_fifo == -1 || min_fifo == -1) {
        perror("sched_get_priority failed for SCHED_FIFO");
        return 1;
    }

    // 2. Retrieve priorities for SCHED_RR (Round-Robin real-time policy)
    max_rr = sched_get_priority_max(SCHED_RR);
    min_rr = sched_get_priority_min(SCHED_RR);

    if (max_rr == -1 || min_rr == -1) {
        perror("sched_get_priority failed for SCHED_RR");
        return 1;
    }

    // 3. Print the results
    printf("--- Real-Time Priority Ranges in Linux ---\n");
    printf("SCHED_FIFO -> Minimum Priority: %d, Maximum Priority: %d\n", min_fifo, max_fifo);
    printf("SCHED_RR   -> Minimum Priority: %d, Maximum Priority: %d\n", min_rr, max_rr);

    return 0;
}
/*
output: 
--- Real-Time Priority Ranges in Linux ---
SCHED_FIFO -> Minimum Priority: 1, Maximum Priority: 99
SCHED_RR   -> Minimum Priority: 1, Maximum Priority: 99



*/
