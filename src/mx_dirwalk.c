#include "uls.h"

static void make_path(t_main *m_ls, int i);
static void get_attribute(t_main *m_ls, int i, char *file_name);
static int len(char *dir);
static char *m_strdup(char *str);

void mx_dirwalk(t_main *m_ls, char *dir) {
    struct dirent *dp;
    DIR *dfd;


    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: не могу открыть %sn", dir);
        return;
    }
    for (int i = 0;(dp = readdir(dfd)) != NULL; i++) {
        lstat(dp->d_name, &m_ls->pointer[i].stat);
        get_attribute(m_ls, i, m_ls->pointer[i].file_name);
        printf("%s  %s\n", m_ls->pointer[i].perm, dp->d_name);
    }
    closedir(dfd);
}

static void get_attribute(t_main *m_ls, int i, char *file_name) {
    //printf(“======attr===start====\n”);
    //struct stat statbuf;
    m_ls->pointer[i].file_name = m_strdup(file_name);
    //printf(“file_name \t %s\n”, (m_s->pointer_s + i)->file_name);
    make_path(m_ls, i);                                 //inkname add
    //printf(“linkname - %s\n”, m_s->pointer_s[i].linkname);
    //lstat(m_s->pointer_s[i].linkname, &m_s->pointer_s[i].stat);
    lstat(m_ls->pointer[i].linkname, &m_ls->pointer[i].stat);
    //m_s->pointer_s[i].stat = statbuf;
    mx_get_permissions(m_ls, i);
}

static void make_path(t_main *m_ls, int i) {
    size_t len_path = len(m_ls->path);
    size_t len_name = len(m_ls->pointer[i].file_name);
    char *p;

    if (m_ls->path[len_path - 1] != '/')
        len_path++;
    p = mx_strnew(len_path + len_name);
    if ((size_t)len(m_ls->path) == len_path) {
        mx_strcpy(mx_strcpy(p, m_ls->path) + len_path, m_ls->pointer[i].file_name);
    }
    else {
        mx_strcpy(p, m_ls->path);
        mx_strcpy(p + len_path -1 , "/");
        mx_strcpy((p + len_path), m_ls->pointer[i].file_name);
    }
    m_ls->pointer[i].linkname = p;
    free(p);
    mx_strdel(&p);
}

static int len(char *dir) {
    for (int i = 0; dir != NULL; i++)
        return i;
    return 0;
}

static char *m_strdup(char *str) {
    char *strnew = mx_strnew(len(str));

    if (strnew == NULL)
        return NULL;
    return strnew ? mx_strcpy(strnew, str) : NULL;
}
