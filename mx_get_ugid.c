#include "uls.h"

void mx_get_ugid(t_dir *m_ls, int i) {
    struct passwd *pwd;
    struct group *grp;

    pwd = getpwuid(m_ls->pointer[i].stat.st_uid);
    if (pwd->pw_name != NULL)
        m_ls->pointer[i].user_name = mx_strdup(pwd->pw_name);
    else {
        m_ls->pointer[i].user_name = mx_itoa(m_ls->pointer[i].stat.st_uid);
    }
    grp = getgrgid(m_ls->pointer[i].stat.st_gid);
    if (grp != NULL)
        m_ls->pointer[i].group_name = mx_strdup(grp->gr_name);
    else {
        m_ls->pointer[i].group_name = mx_itoa(m_ls->pointer[i].stat.st_gid);
    }
}
