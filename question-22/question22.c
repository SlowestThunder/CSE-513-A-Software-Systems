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
        printf("Child process (PID: %d) executing and exiting immediately...\n", getpid());
        exit(0); // Child terminates, turning into a zombie because parent hasn't called wait()
    } 
    else {
        // --- Parent Process ---
        printf("Parent process (PID: %d) is sleeping. Child (PID: %d) is now a zombie.\n", getpid(), pid);
        
        // Sleep for 30 seconds without calling wait(), giving you time to check 'ps'
        sleep(30); 
        
        printf("Parent waking up and terminating.\n");
    }

    return 0;
}
/*
output:
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND

ravi        9187  0.0  0.0      0     0 ?        Z    Sep18   0:00 [xdg-terminal-ex] <defunct>
ravi       38053 18.3  9.0 1520449920 633192 ?   Sl   17:55   9:24 /snap/brave/684/opt/brave.com/brave/brave --type=renderer --crashpad-handler-pid=37951 --enable-crash-reporter=7dde5ae9-adab-4c24-9acf-d89cf8fd5483, --enable-distillability-service --origin-trial-public-key=bYUKPJoPnCxeNvu72j4EmPuK7tr1PAC7SHh8ld9Mw3E=,fMS4mpO6buLQ/QMd+zJmxzty/VQ6B1EUZqoCU04zoRU= --change-stack-guard-on-fork=enable --ozone-platform=wayland --lang=en-US --num-raster-threads=4 --enable-main-frame-before-activation --renderer-client-id=6 --launch-time-ticks=31148531355 --shared-files=v8_context_snapshot_data:100 --metrics-shmem-handle=4,i,13655749274397479794,1144739104976875764,1572864 --field-trial-handle=3,i,13531381917621690249,4604634256013432665,262144 --variations-seed-version=main@6ff3baf661e484ef285861bc399c1df5322d04f8 --pseudonymization-salt-handle=7,i,427153076914682551,6407311403085734769,4 --trace-process-track-uuid=3190708991934122588
ravi       38143  0.1  2.7 1518386068 194984 ?   Sl   17:55   0:05 /snap/brave/684/opt/brave.com/brave/brave --type=renderer --crashpad-handler-pid=37951 --enable-crash-reporter=7dde5ae9-adab-4c24-9acf-d89cf8fd5483, --enable-distillability-service --origin-trial-public-key=bYUKPJoPnCxeNvu72j4EmPuK7tr1PAC7SHh8ld9Mw3E=,fMS4mpO6buLQ/QMd+zJmxzty/VQ6B1EUZqoCU04zoRU= --change-stack-guard-on-fork=enable --ozone-platform=wayland --lang=en-US --num-raster-threads=4 --enable-main-frame-before-activation --renderer-client-id=7 --launch-time-ticks=31148772232 --shared-files=v8_context_snapshot_data:100 --metrics-shmem-handle=4,i,17958739690246675185,9619259309146931250,1572864 --field-trial-handle=3,i,13531381917621690249,4604634256013432665,262144 --variations-seed-version=main@6ff3baf661e484ef285861bc399c1df5322d04f8 --pseudonymization-salt-handle=7,i,427153076914682551,6407311403085734769,4 --trace-process-track-uuid=3190708992871164437
ravi       38171  0.0  1.1 1518300764 82444 ?    Sl   17:55   0:00 /snap/brave/684/opt/brave.com/brave/brave --type=renderer --crashpad-handler-pid=37951 --enable-crash-reporter=7dde5ae9-adab-4c24-9acf-d89cf8fd5483, --enable-distillability-service --origin-trial-public-key=bYUKPJoPnCxeNvu72j4EmPuK7tr1PAC7SHh8ld9Mw3E=,fMS4mpO6buLQ/QMd+zJmxzty/VQ6B1EUZqoCU04zoRU= --change-stack-guard-on-fork=enable --ozone-platform=wayland --lang=en-US --num-raster-threads=4 --enable-main-frame-before-activation --renderer-client-id=8 --launch-time-ticks=31149239900 --shared-files=v8_context_snapshot_data:100 --metrics-shmem-handle=4,i,14037777832538973744,14493293238076108491,1572864 --field-trial-handle=3,i,13531381917621690249,4604634256013432665,262144 --variations-seed-version=main@6ff3baf661e484ef285861bc399c1df5322d04f8 --pseudonymization-salt-handle=7,i,427153076914682551,6407311403085734769,4 --trace-process-track-uuid=3190708993808206286
ravi       41631  0.0  0.0      0     0 pts/1    Z+   18:46   0:00 [question22] <defunct>
ravi       41677  0.0  0.0   9316  2600 pts/0    S+   18:46   0:00 grep --color=auto Z


*/
