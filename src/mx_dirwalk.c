#include "uls.h"

static void make_path(t_dir *m_ls, int i) {
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
        mx_strcpy(p + len_path - 1 , "/");
        mx_strcpy((p + len_path), m_ls->pointer[i].file_name);
    }
    m_ls->pointer[i].linkname = p;
}

static void get_attribute(t_dir *m_ls, int i, char *file_name) {
    struct stat statbuf;
    m_ls->pointer[i].file_name = mx_strdup(file_name);
    make_path(m_ls, i);
    lstat(m_ls->pointer[i].linkname, &statbuf);
    m_ls->pointer[i].stat = statbuf;
    mx_get_permissions(m_ls, i);
    mx_get_ugid(m_ls, i);
    if (SISDIR(m_ls->pointer[i].stat.st_mode) && (m_ls->pointer[i].file_name[0] != '.'))
        m_ls->rec_dir_c += 1;
}

static void get_max(t_dir *m_ls, int i) {
    char *link = mx_itoa(m_ls->pointer[i].stat.st_nlink);
    char *b_size = mx_itoa(m_ls->pointer[i].stat.st_size);

    if (mx_strlen(m_ls->pointer[i].file_name) > m_ls->max_f_size)
        m_ls->max_f_size = mx_strlen(m_ls->pointer[i].file_name);
    if (mx_strlen(m_ls->pointer[i].user_name) > m_ls->max_uid_size)
        m_ls->max_uid_size = mx_strlen(m_ls->pointer[i].user_name);
    if (mx_strlen(m_ls->pointer[i].group_name) > m_ls->max_gid_size)
        m_ls->max_gid_size = mx_strlen(m_ls->pointer[i].group_name);
    if (mx_strlen(link) > m_ls->max_link_size)
        m_ls->max_link_size = mx_strlen(link);
    if (mx_strlen(b_size) > m_ls->max_byte_size)
        m_ls->max_byte_size = mx_strlen(b_size);
    free(b_size);
    free(link);
}

void mx_dirwalk(t_main *ls, char *file_name) {
    t_dir *m_ls = (t_dir *) malloc(sizeof(t_dir));
    struct dirent *dp;
    DIR *dfd;
    m_ls->rec_dir_c = 0;

    mx_init_m_struct(file_name, m_ls);
    dfd = opendir(file_name);
    for (int i = 0;(dp = readdir(dfd)) != NULL; i++) {
        get_attribute(m_ls, i, dp->d_name);
        get_max(m_ls, i);
    }
    closedir(dfd);
    mx_sort_struct(m_ls);
    mx_printstr("\n");
    if (ls->l == 1)
        mx_print_long(m_ls, ls);
    else
        mx_standard_format(ls, m_ls);
    if (ls->R == 1)
        mx_print_recursive(ls, m_ls);
    mx_clean_struct(m_ls);
}
