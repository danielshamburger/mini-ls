#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    DIR *dirPtr;
    struct dirent *entryPtr;
    struct stat statBuf;

    char dirName[32];

    // options flags
    int n = 0, i = 0, s = 0;

    if (argc < 2) {
        printf("Usage: [EXECUTABLE] [OPTIONS] [DIRECTORY]\n");
        exit(1);
    } 

    for (int j = 0; j < argc; j++) {
        if (j == argc - 1)
            strcpy(dirName, argv[j]);

        if (strcmp(argv[j], "-n") == 0)
            n = 1;
        else if(strcmp(argv[j], "-i") == 0)
            i = 1;
        else if(strcmp(argv[j], "-s") == 0)
            s = 1;
    }

    dirPtr = opendir(dirName);

    if (!dirPtr) {
        printf("Directory not found.\n");
        exit(1);
    }

    while (entryPtr = readdir(dirPtr)) {
        if (stat(entryPtr->d_name, &statBuf) < 0) {
            perror("Stat call error");
            exit(1);
        }

        if (n) {
            printf("%d\t", statBuf.st_uid);
            printf("%d\t", statBuf.st_gid);
        }

        if (i)
            printf("%lu\t", statBuf.st_ino);

        if (s) {
            printf("%ld\t", statBuf.st_size);
            printf("%ld\t", statBuf.st_blocks);
        }

        printf("%-20s\n", entryPtr->d_name);
    }
    closedir(dirPtr);

    printf("\n");

    return 0;
}
