#include "uls.h"

void mx_init_m_struct(char *dir, t_dir *m_ls) {
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
    m_ls->path = mx_strdup(dir);
    t_file *file_arr = (t_file *)malloc(sizeof(t_file) * m_ls->file_count);
    m_ls->pointer = file_arr;
    m_ls->max_f_size = 0;
    m_ls->max_link_size = 0;
    m_ls->max_uid_size = 0;
    m_ls->max_gid_size = 0;
    m_ls->max_byte_size = 0;
//    free(file_arr);
}
