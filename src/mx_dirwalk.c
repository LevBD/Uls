#include "uls.h"

static void make_path(t_main *m_ls, int i);
static void get_attribute(t_main *m_ls, int i, char *file_name);
static void get_max(t_main *m_ls, int i);
//static void init_s_file(t_main *m_s, char *path);

void mx_dirwalk(t_main *m_ls, char *file_name) {
    struct dirent *dp;
    DIR *dfd;

//    init_s_file(m_ls, file_name);
//    t_file *file_arr = (t_file *)malloc(sizeof(t_file) * m_ls->file_count);
//    m_ls->pointer = file_arr;
//    mx_init_m_struct(file_name, m_ls);
    dfd = opendir(file_name);
    for (int i = 0;(dp = readdir(dfd)) != NULL; i++) {
        get_attribute(m_ls, i, dp->d_name);
        get_max(m_ls, i);
    }
    closedir(dfd);
}

//static void init_s_file(t_main *m_ls, char *path) {
//    DIR *dir;
//    struct dirent *dp;
//    int size = 0;
//
//    dir = opendir(path);
//
//    if (dir == NULL)
//        exit(-1);
//    while ((dp =readdir(dir)) != NULL) {
//        size++;
//    }
//    closedir(dir);
//
//    m_ls->path = path;
//    m_ls->file_count = size;
//}

static void get_attribute(t_main *m_ls, int i, char *file_name) {
    struct stat statbuf;
    m_ls->pointer[i].file_name = mx_strdup(file_name);
    make_path(m_ls, i);
    lstat(m_ls->pointer[i].linkname, &statbuf);
    m_ls->pointer[i].stat = statbuf;
    mx_get_permissions(m_ls, i);
    mx_get_ugid(m_ls, i);
}

static void make_path(t_main *m_ls, int i) {
    size_t len_path = mx_strlen(m_ls->path);
    size_t len_name = mx_strlen(m_ls->pointer[i].file_name);
    char *p;

    if (m_ls->path[len_path - 1] != '/')
        len_path++;
    p = mx_strnew(len_path + len_name);
    if ((size_t)mx_strlen(m_ls->path) == len_path) {
        mx_strcpy(mx_strcpy(p, m_ls->path) + len_path, m_ls->pointer[i].file_name);
    }
    else {
        mx_strcpy(p, m_ls->path);
        mx_strcpy(p + len_path -1 , "/");
        mx_strcpy((p + len_path), m_ls->pointer[i].file_name);
    }
    m_ls->pointer[i].linkname = p;
}

static void get_max(t_main *m_ls, int i) {
    if (mx_strlen(m_ls->pointer[i].file_name) > m_ls->max_f_size)
        m_ls->max_f_size = mx_strlen(m_ls->pointer[i].file_name);
    if (mx_strlen(m_ls->pointer[i].user_name) > m_ls->max_uid_size)
        m_ls->max_uid_size = mx_strlen(m_ls->pointer[i].user_name);
    if (mx_strlen(m_ls->pointer[i].group_name) > m_ls->max_gid_size)
        m_ls->max_gid_size = mx_strlen(m_ls->pointer[i].group_name);
    if (mx_strlen(mx_itoa(m_ls->pointer[i].stat.st_nlink)) > m_ls->max_link_size)
        m_ls->max_link_size = mx_strlen(mx_itoa(m_ls->pointer[i].stat.st_nlink));
    if (mx_strlen(mx_itoa(m_ls->pointer[i].stat.st_size)) > m_ls->max_byte_size)
        m_ls->max_byte_size = mx_strlen(mx_itoa(m_ls->pointer[i].stat.st_size));
}
