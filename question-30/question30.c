#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

void create_daemon() {
    pid_t pid = fork();

    if (pid < 0) exit(1); // Fork failure
    if (pid > 0) exit(0); // Parent exits, letting child run in background

    // Child process continues here
    if (setsid() < 0) exit(1); // Create a new session

    // Fork again to prevent acquiring a controlling terminal
    pid = fork();
    if (pid < 0) exit(1);
    if (pid > 0) exit(0);

    // Set file permissions
    umask(0);

    // Change working directory to root
    chdir("/");

    // Close standard file descriptors (stdin, stdout, stderr)
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main() {
    // 1. Turn into a background daemon process
    create_daemon();

    // 2. Define target delay (e.g., execute task after 10 seconds for demo purposes)
    // In a real application, you can compare current time with a target hour/minute struct tm.
    int delay_seconds = 10; 
    sleep(delay_seconds);

    // 3. Perform the scheduled task (e.g., log into a file in /tmp/)
    FILE *log_file = fopen("/tmp/daemon_task.log", "a");
    if (log_file != NULL) {
        time_t rawtime;
        time(&rawtime);
        fprintf(log_file, "Daemon executed scheduled task successfully at: %s", ctime(&rawtime));
        fclose(log_file);
    }

    return 0;
}
/*
output:
Daemon executed scheduled task successfully at: Mon Sep 21 21:00:51 2026

*/
