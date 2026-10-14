#include <stdio.h>
#include <unistd.h>

int main() {
    int result = link("target.txt", "hard_link_sc.txt");

    if (result == 0) {
        printf("Hard link created successfully.\n");
    } else {
        perror("Error creating hard link");
    }

    return 0;
}
/*
output:
-rw-rw-r-- 3 ravi ravi 12 Sep 14 18:14 hard_link.txt
-rw-rw-r-- 3 ravi ravi 12 Sep 14 18:14 hard_link_sc.txt
prw-rw-r-- 1 ravi ravi  0 Sep 18 18:52 my_fifo
prw-rw-r-- 1 ravi ravi  0 Sep 14 18:47 my_fifo_mkfifo
prw-rw-r-- 1 ravi ravi  0 Sep 14 18:46 my_fifo_mknod
lrwxrwxrwx 1 ravi ravi 10 Sep 14 18:15 soft_link.txt -> target.txt
lrwxrwxrwx 1 ravi ravi 10 Sep 14 18:32 soft_link_sc.txt -> target.txt
-rw-rw-r-- 3 ravi ravi 12 Sep 14 18:14 target.txt
*/
