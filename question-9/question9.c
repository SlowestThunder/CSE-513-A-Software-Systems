#include <stdio.h>
#include <sys/stat.h>
#include <time.h> 
int main() {
    struct stat s;

    if (stat("file1.txt", &s) < 0) {
        printf("Error: Could not read file information!\n");
        return 1;
    }

    printf("a. Inode Number:         %lu\n", s.st_ino);
    printf("b. Hard Links:           %lu\n", s.st_nlink);
    printf("c. UID:                  %u\n",  s.st_uid);
    printf("d. GID:                  %u\n",  s.st_gid);
    printf("e. Size (bytes):         %ld\n", s.st_size);
    printf("f. Block Size:           %ld\n", s.st_blksize);
    printf("g. Allocated Blocks:     %ld\n", s.st_blocks);
    printf("h. Last Access Time:     %s", ctime(&s.st_atime));
    printf("i. Last Mod Time:        %s", ctime(&s.st_mtime));
    printf("j. Last Change Time:     %s", ctime(&s.st_ctime));

    return 0;
}
/*
output:
a. Inode Number:         1858201
b. Hard Links:           1
c. UID:                  1000
d. GID:                  1000
e. Size (bytes):         22
f. Block Size:           4096
g. Allocated Blocks:     8
h. Last Access Time:     Fri Sep 18 22:57:00 2026
i. Last Mod Time:        Fri Sep 18 22:57:00 2026
j. Last Change Time:     Fri Sep 18 23:03:38 2026
*/
