#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// a. execl: Full path required, arguments passed as a list
void run_execl() {
    if (fork() == 0) {
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl failed");
        exit(1);
    }
    wait(NULL);
}

// b. execlp: Searches PATH variable, arguments passed as a list
void run_execlp() {
    if (fork() == 0) {
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp failed");
        exit(1);
    }
    wait(NULL);
}

// c. execle: Full path, arguments as a list, plus explicit environment pointer
void run_execle() {
    if (fork() == 0) {
        char *env[] = { "TERM=console", NULL };
        execle("/bin/ls", "ls", "-Rl", NULL, env);
        perror("execle failed");
        exit(1);
    }
    wait(NULL);
}

// d. execv: Full path, arguments passed as an array (vector)
void run_execv() {
    if (fork() == 0) {
        char *args[] = { "ls", "-Rl", NULL };
        execv("/bin/ls", args);
        perror("execv failed");
        exit(1);
    }
    wait(NULL);
}

// e. execvp: Searches PATH variable, arguments passed as an array (vector)
void run_execvp() {
    if (fork() == 0) {
        char *args[] = { "ls", "-Rl", NULL };
        execvp("ls", args);
        perror("execvp failed");
        exit(1);
    }
    wait(NULL);
}

int main() {
    int choice;
    printf("--- Exec System Calls Demo for 'ls -Rl' ---\n");
    printf("1. execl\n");
    printf("2. execlp\n");
    printf("3. execle\n");
    printf("4. execv\n");
    printf("5. execvp\n");
    printf("Enter choice (1-5): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: run_execl(); break;
        case 2: run_execlp(); break;
        case 3: run_execle(); break;
        case 4: run_execv(); break;
        case 5: run_execvp(); break;
        default: printf("Invalid choice!\n");
    }

    return 0;
}
/*
output:
.:
total 48
-rwxrwxr-x 1 ravi ravi 16656 Sep 21 19:50 a.out
-rw-rw-r-- 1 ravi ravi    13 Sep 21 19:52 file1.txt
-rwxrwxr-x 1 ravi ravi 16656 Sep 21 19:50 question26
-rw-rw-r-- 1 ravi ravi  1948 Sep 21 19:50 question26.c





*/
