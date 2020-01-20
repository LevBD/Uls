#include "uls.h"

void mx_dirwalk(char *dir) {
    struct dirent *dp;
    DIR *dfd;
    struct stat buf;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: не могу открыть %sn", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        lstat(dp->d_name, &buf);
        printf("%s/%d\n", dp->d_name, buf.st_nlink);
    }

    closedir(dfd);
}
