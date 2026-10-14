#include <stdio.h>
#include <fcntl.h>   // Required for creat() system call
#include <unistd.h>  // Required for getpid() and sleep()

int main() {
    int fds[5];
    char filename[20];

    // Print the process ID so we know which /proc directory to inspect
    printf("Process ID (PID): %d\n", getpid());

    // Create 5 new files using creat()
    for (int i = 0; i < 5; i++) {
        sprintf(filename, "file_%d.txt", i + 1);
        
        // S_IRUSR | S_IWUSR gives read/write permissions to the owner (0600)
        fds[i] = creat(filename, S_IRUSR | S_IWUSR);

        if (fds[i] < 0) {
            perror("Error creating file");
            return 1;
        }

        printf("Created %s with File Descriptor: %d\n", filename, fds[i]);
    }

    printf("Entering infinite loop. Inspect /proc/%d/fd now...\n", getpid());

    // Infinite loop keeps the process alive so the file descriptors remain open
    while (1) {
        sleep(1);
    }

    return 0;
}
/*
output:
[1] 62564
Process ID (PID): 62564
Created file_1.txt with File Descriptor: 3
Created file_2.txt with File Descriptor: 4
Created file_3.txt with File Descriptor: 5
Created file_4.txt with File Descriptor: 6
Created file_5.txt with File Descriptor: 7
Entering infinite loop. Inspect /proc/62564/fd now...


total 0
lrwx------ 1 ravi ravi 64 Sep 22 00:30 0 -> /dev/pts/1
lrwx------ 1 ravi ravi 64 Sep 22 00:30 1 -> /dev/pts/1
lrwx------ 1 ravi ravi 64 Sep 22 00:30 2 -> /dev/pts/1
l-wx------ 1 ravi ravi 64 Sep 22 00:30 3 -> /home/ravi/Desktop/hands_on_list1_code/question-5/file_1.txt
l-wx------ 1 ravi ravi 64 Sep 22 00:30 4 -> /home/ravi/Desktop/hands_on_list1_code/question-5/file_2.txt
l-wx------ 1 ravi ravi 64 Sep 22 00:30 5 -> /home/ravi/Desktop/hands_on_list1_code/question-5/file_3.txt
l-wx------ 1 ravi ravi 64 Sep 22 00:30 6 -> /home/ravi/Desktop/hands_on_list1_code/question-5/file_4.txt
l-wx------ 1 ravi ravi 64 Sep 22 00:30 7 -> /home/ravi/Desktop/hands_on_list1_code/question-5/file_5.txt
*/
