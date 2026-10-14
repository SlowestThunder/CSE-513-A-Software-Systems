#include <stdio.h>
#include <unistd.h>

int main() {
    // getpid() retrieves the Process ID of the currently running program
    printf("Program running in background. Process ID (PID): %d\n", getpid());
    
    // Infinite loop to keep the process running continuously
    while (1) {
        sleep(1); // Sleep for 1 second to avoid using 100% CPU
    }

    return 0;
}
/*
Output:
total 0
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 arch_status
dr-xr-xr-x  2 ravi ravi 0 Sep 22 00:22 attr
-rw-r--r--  1 ravi ravi 0 Sep 22 00:22 autogroup
-r--------  1 ravi ravi 0 Sep 22 00:22 auxv
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 cgroup
--w-------  1 ravi ravi 0 Sep 22 00:22 clear_refs
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 cmdline
-rw-r--r--  1 ravi ravi 0 Sep 22 00:22 comm
-rw-r--r--  1 ravi ravi 0 Sep 22 00:22 coredump_filter
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 cpu_resctrl_groups
lrwxrwxrwx  1 ravi ravi 0 Sep 22 00:22 cwd -> /home/ravi/Desktop/hands_on_list1_code/question-2
-r--------  1 ravi ravi 0 Sep 22 00:22 environ
lrwxrwxrwx  1 ravi ravi 0 Sep 22 00:22 exe -> /home/ravi/Desktop/hands_on_list1_code/question-2/question2
dr-x------  2 ravi ravi 3 Sep 22 00:22 fd
dr-xr-xr-x  2 ravi ravi 0 Sep 22 00:22 fdinfo
-rw-r--r--  1 ravi ravi 0 Sep 22 00:22 gid_map
-r--------  1 ravi ravi 0 Sep 22 00:22 io
-r--------  1 ravi ravi 0 Sep 22 00:22 ksm_merging_pages
-r--------  1 ravi ravi 0 Sep 22 00:22 ksm_stat
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 latency
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 limits
-rw-r--r--  1 ravi ravi 0 Sep 22 00:22 loginuid
dr-x------  2 ravi ravi 0 Sep 22 00:22 map_files
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 maps
-rw-------  1 ravi ravi 0 Sep 22 00:22 mem
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 mountinfo
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 mounts
-r--------  1 ravi ravi 0 Sep 22 00:22 mountstats
dr-xr-xr-x 56 ravi ravi 0 Sep 22 00:22 net
dr-x--x--x  2 ravi ravi 0 Sep 22 00:22 ns
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 numa_maps
-rw-r--r--  1 ravi ravi 0 Sep 22 00:22 oom_adj
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 oom_score
-rw-r--r--  1 ravi ravi 0 Sep 22 00:22 oom_score_adj
-r--------  1 ravi ravi 0 Sep 22 00:22 pagemap
-r--------  1 ravi ravi 0 Sep 22 00:22 patch_state
-r--------  1 ravi ravi 0 Sep 22 00:22 personality
-rw-r--r--  1 ravi ravi 0 Sep 22 00:22 projid_map
lrwxrwxrwx  1 ravi ravi 0 Sep 22 00:22 root -> /
-rw-r--r--  1 ravi ravi 0 Sep 22 00:22 sched
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 schedstat
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 sessionid
-rw-r--r--  1 ravi ravi 0 Sep 22 00:22 setgroups
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 smaps
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 smaps_rollup
-r--------  1 ravi ravi 0 Sep 22 00:22 stack
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 stat
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 statm
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 status
-r--------  1 ravi ravi 0 Sep 22 00:22 syscall
dr-xr-xr-x  3 ravi ravi 0 Sep 22 00:22 task
-rw-r--r--  1 ravi ravi 0 Sep 22 00:22 timens_offsets
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 timers
-rw-rw-rw-  1 ravi ravi 0 Sep 22 00:22 timerslack_ns
-rw-r--r--  1 ravi ravi 0 Sep 22 00:22 uid_map
-r--r--r--  1 ravi ravi 0 Sep 22 00:22 wchan
*/
