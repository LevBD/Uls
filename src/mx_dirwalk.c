#include "uls.h"

void dirwalk(char *dir) {
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: не могу открыть %sn", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        printf("%s/%s\n", dir, dp->d_name);
    }
    closedir(dfd);
}
