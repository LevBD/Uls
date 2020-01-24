#include "uls.h"

static char *get_type(t_main *m_ls, int i, char *res);

void mx_get_permissions(t_main *m_ls, int i) {
    char *res = mx_strnew(10);

    get_type(m_ls, i, res);
    res[1] = (S_IRUSR & m_ls->pointer[i].stat.st_mode) ? 'r' : '-';
    res[2] = (S_IWUSR & m_ls->pointer[i].stat.st_mode) ? 'w' : '-';
    res[3] = (m_ls->pointer[i].stat.st_mode & S_IXUSR) ?
             ((m_ls->pointer[i].stat.st_mode & S_ISUID) ? 's' : 'x') :
    ((m_ls->pointer[i].stat.st_mode & S_ISUID) ? 'S' : '-');
    res[4] = (S_IRGRP & m_ls->pointer[i].stat.st_mode) ? 'r' : '-';
    res[5] = (S_IWGRP & m_ls->pointer[i].stat.st_mode) ? 'w' : '-';
    res[6] = (m_ls->pointer[i].stat.st_mode& S_IXGRP) ?
             ((m_ls->pointer[i].stat.st_mode& S_ISGID) ? 's' : 'x') :
    ((m_ls->pointer[i].stat.st_mode & S_ISGID) ? 'S' : '-');
    res[7] = (S_IROTH & m_ls->pointer[i].stat.st_mode) ? 'r' : '-';
    res[8] = (S_IWOTH & m_ls->pointer[i].stat.st_mode) ? 'w' : '-';
    res[9] = (m_ls->pointer[i].stat.st_mode & S_IXOTH) ?
             ((m_ls->pointer[i].stat.st_mode & S_ISTXT) ? 't' : 'x') :
    ((m_ls->pointer[i].stat.st_mode & S_ISTXT) ? 'T' : '-');
    m_ls->pointer[i].perm = mx_strdup(res);
    free(res);
}

static char *get_type(t_main *m_ls, int i, char *res) {

    res[0] = S_ISBLK(m_ls->pointer[i].stat.st_mode) ? 'b' :
    S_ISCHR(m_ls->pointer[i].stat.st_mode) ? 'c' :
    S_ISDIR(m_ls->pointer[i].stat.st_mode) ? 'd' :
    S_ISSOCK(m_ls->pointer[i].stat.st_mode) ? 's' :
    S_ISFIFO(m_ls->pointer[i].stat.st_mode) ? 'p' :
    S_ISLNK(m_ls->pointer[i].stat.st_mode) ? 'l' : '-';
    return res;
}
