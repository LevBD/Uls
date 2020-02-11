#include "uls.h"

static void clean_struct_s_file(t_file *file);

void mx_clean_struct(t_dir *m_ls) {
    mx_strdel(&m_ls->path);
    for (int i = 0; i < m_ls->file_count; i++)
            clean_struct_s_file(&m_ls->pointer[i]);
}

//typedef struct s_file {
//    struct stat stat;
//    char  *perm;
//    char *file_name;
//    char *linkname;
//    char *user_name;
//    char *group_name;
//} t_file;
//
//typedef struct s_dir {
//    t_file *pointer;
//    int file_count;
//    char *path;
//    int rec_dir_c;
//
//    int max_f_size;
//    int max_uid_size;
//    int max_gid_size;
//    int max_link_size;
//    int max_byte_size;
//} t_dir;

static void clean_struct_s_file(t_file *file) {
    mx_strdel(&file->file_name);
    mx_strdel(&file->group_name);
    mx_strdel(&file->perm);
    mx_strdel(&file->user_name);
//    free(&file->stat.st_size);
//    mx_strdel(&file->linkname);
}
