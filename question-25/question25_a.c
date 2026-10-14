#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec: My PID is %d\n", getpid());
    printf("Executing 'ls' command using execlp...\n\n");

    // execlp replaces the current process image with 'ls'
    // Format: execlp("command", "command", NULL)
    execlp("ls", "ls", NULL);

    // This line only executes if execlp fails
    perror("exec failed");
    return 1;
}
/*
output:


*/

