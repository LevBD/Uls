#include "uls.h"

void mx_init_m_struct(char *dir, t_main *m_ls) {
    struct dirent *dp;
    DIR *dfd;
    int size = 0;


    dfd = opendir(dir);
    if (dir == NULL)
        exit(-1);
    while ((dp = readdir(dfd)) != NULL) {
        size++;
    }
    closedir(dfd);
    m_ls->file_count = size;
    m_ls->path = dir;
    t_file *file_arr = (t_file *)malloc(sizeof(t_file) * m_ls->file_count);
    m_ls->pointer = file_arr;
}
