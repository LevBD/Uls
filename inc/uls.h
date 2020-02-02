#ifndef ULS_H
#define ULS_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <stdio.h>
#include <fcntl.h>

#include "libmx/inc/libmx.h"

typedef struct s_main {
    char **file_arr;
    char **dir_arr;
    char **err_arr;
    char *dir_name;

    int f_count;
    int d_count;
    int e_count;
} t_main;

typedef struct s_file {
    struct stat stat;
    char  *perm;
    char *file_name;
    char *linkname;
    char *user_name;
    char *group_name;
} t_file;

typedef struct s_dir {
    t_file *pointer;
    int file_count;
    char *path;

    int max_f_size;
    int max_uid_size;
    int max_gid_size;
    int max_link_size;
    int max_byte_size;
} t_dir;

char *mx_abs_path(char *name);
void mx_dirwalk(t_main *ls, char *file_name);
void mx_get_permissions(t_dir *m_ls, int i);
void mx_init_m_struct(char *dir, t_dir *m_ls);
void mx_print_long(t_dir *m_ls);
void mx_sort_struct(t_dir *m_ls);
void mx_get_ugid(t_dir *m_ls, int i);
//void mx_print_acl(t_main *m_ls, int i);
void mx_print_acl(char *file);
void mx_print_specific_time(time_t t);
void mx_print_total_blocks(t_dir *m_ls);
char mx_get_type_file(struct stat buf, char a);
void mx_array_filling(t_main *ls, char** argv, int argc);
void mx_filling_array_dir(t_main *ls);
void mx_array_count(t_main *ls, char** argv, int argc);

#endif
