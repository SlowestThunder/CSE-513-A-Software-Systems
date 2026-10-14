#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *src = fopen("file1.txt", "r");
    if (src == NULL) {
        printf("Error: Cannot open source file!\n");
        return 1;
    }

    FILE *dest = fopen("file2.txt", "w");
    if (dest == NULL) {
        printf("Error: Cannot create destination file!\n");
        fclose(src);
        return 1;
    }

    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest); // Write each character to destination file
    }

    printf("File copied successfully!\n");

    fclose(src);
    fclose(dest);

    return 0;
}
/*
output:
File copied successfully!


-rw-rw-r-- 1 ravi ravi 34 Sep 18 18:35 file1.txt
-rw-rw-r-- 1 ravi ravi 34 Sep 22 00:34 file2.txt
*/
