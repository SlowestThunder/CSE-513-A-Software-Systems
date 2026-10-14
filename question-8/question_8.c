#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("file1.txt", "r");

    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        return 1;
    }

    char line[256];

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
    printf("\nFile closed successfully.\n");

    return 0;
}
/*
output:
Hello, My dear Friend

File closed successfully.
*/
