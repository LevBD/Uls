#include "uls.h"

static char *get_type(t_main *m_ls, int i, char *res);

void mx_get_permissions(t_main *m_ls, int i) {
    char *res = mx_strnew(10);
    t_file *file = &m_ls->pointer[i];

    get_type(m_ls, i, res);
    res[1] = (S_IRUSR & file->stat.st_mode) ? 'r' : '-';
    res[2] = (S_IWUSR & file->stat.st_mode) ? 'w' : '-';
    res[3] = (file->stat.st_mode & S_IXUSR) ?
             ((file->stat.st_mode & S_ISUID) ? 's' : 'x') :
    ((file->stat.st_mode & S_ISUID) ? 'S' : '-');
    res[4] = (S_IRGRP & file->stat.st_mode) ? 'r' : '-';
    res[5] = (S_IWGRP & file->stat.st_mode) ? 'w' : '-';
    res[6] = (file->stat.st_mode & S_IXGRP) ?
             ((file->stat.st_mode & S_ISGID) ? 's' : 'x') :
    ((file->stat.st_mode & S_ISGID) ? 'S' : '-');
    res[7] = (S_IROTH & file->stat.st_mode) ? 'r' : '-';
    res[8] = (S_IWOTH & file->stat.st_mode) ? 'w' : '-';
    res[9] = (file->stat.st_mode & S_IXOTH) ?
             ((file->stat.st_mode & S_ISTXT) ? 't' : 'x') :
    ((file->stat.st_mode & S_ISTXT) ? 'T' : '-');
    file->perm = mx_strdup(res);
    free(res);
}

static char *get_type(t_main *m_ls, int i, char *res) {
    t_file *file = &m_ls->pointer[i];
    res[0] = S_ISBLK(file->stat.st_mode) ? 'b' :
    S_ISCHR(file->stat.st_mode) ? 'c' :
    S_ISDIR(file->stat.st_mode) ? 'd' :
    S_ISSOCK(file->stat.st_mode) ? 's' :
    S_ISFIFO(file->stat.st_mode) ? 'p' :
    S_ISLNK(file->stat.st_mode) ? 'l' : '-';
    return res;
}
