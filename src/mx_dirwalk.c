#include "uls.h"

void mx_dirwalk(t_main *m_ls, char *dir) {
    struct dirent *dp;
    DIR *dfd;


    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: не могу открыть %sn", dir);
        return;
    }
    for (int i = 0;(dp = readdir(dfd)) != NULL; i++) {
        stat(dp->d_name, &m_ls->pointer[i].stat);
        mx_get_permissions(m_ls, i);
        printf("%s  %s\n", m_ls->pointer[i].perm, dp->d_name);
    }
    closedir(dfd);
}
