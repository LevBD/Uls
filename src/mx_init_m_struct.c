#include "uls.h"

void mx_init_m_struct(char *dir, t_main *m_ls) {
    struct dirent *dp;
    DIR *dfd;
    int size = 0;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: не открыть %sn", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL)
        size++;
    closedir(dfd);
    t_file *file_arr = (t_file*)malloc(sizeof(t_file) * size);
    m_ls->pointer = file_arr;
    m_ls->file_count = size;
}
