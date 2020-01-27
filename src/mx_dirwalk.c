#include "uls.h"
static void make_path(t_main *m_ls, int i);
static void get_attribute(t_main *m_ls, int i, char *file_name);
static void init_s_file(t_main *m_s, char *path);

void mx_dirwalk(t_main *m_ls, char *file_name) {
    struct dirent *dp;
    DIR *dfd;

    init_s_file(m_ls, file_name);
    t_file *file_arr = (t_file *)malloc(sizeof(t_file) * m_ls->file_count);
    m_ls->pointer = file_arr;

    if ((dfd = opendir(file_name)) == NULL) {
        fprintf(stderr, "dirwalk: не могу открыть %sn", file_name);
        return;
    }
    for (int i = 0;(dp = readdir(dfd)) != NULL; i++) {
        get_attribute(m_ls, i, dp->d_name);
    }
    closedir(dfd);
    
}


static void init_s_file(t_main *m_ls, char *path) {
    DIR *dir;
    struct dirent *dp;
    int size = 0;

    dir = opendir(path);

    if (dir == NULL)
        exit(-1);
    while ((dp =readdir(dir)) != NULL) {
        size++;
    }
    closedir(dir);
    //printf(“sise_dir\t %d\n”, size);
    /* win size */
  //  struct winsize ws;
 //   ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
//    int win_size = ws.ws_col;
  //  m_s->win_size = win_size;
    m_ls->path = path;
    m_ls->file_count = size;


  //  m_s->max_n_file_size = 0;
 //   m_s->max_uid_size = 0;
 //   m_s->max_gid_size = 0;                        //!!!!!!attention
//    m_s->max_link_size = 0;
 //   m_s->max_byte_size = 0;
 //   m_s->rec_dir_c = 0;
}



static void get_attribute(t_main *m_ls, int i, char *file_name) {
    struct stat statbuf;
     m_ls->pointer[i].file_name = mx_strdup(file_name);
     make_path(m_ls, i);
     lstat(m_ls->pointer[i].linkname, &statbuf);
     m_ls->pointer[i].stat = statbuf;
     mx_get_permissions(m_ls, i);
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
