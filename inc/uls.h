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

#define MX_MAJOR(x)  ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
#define MX_MINOR(x)  ((int32_t)((x) & 0xffffff))

#define S_IFMT          0170000         /* type of file mask */
#define S_IFIFO         0010000         /* named pipe (fifo) */
#define S_IFCHR         0020000         /* character special */
#define S_IFDIR         0040000         /* directory */
#define S_IFBLK         0060000         /* block special */
#define S_IFREG         0100000         /* regular */
#define S_IFLNK         0120000         /* symbolic link */
#define S_IFSOCK        0140000         /* socket */

#define SISREG(m)   (((m) & S_IFMT) == S_IFREG)
#define SISDIR(m)   (((m) & S_IFMT) == S_IFDIR)
#define SISCHR(m)   (((m) & S_IFMT) == S_IFCHR)
#define SISBLK(m)   (((m) & S_IFMT) == S_IFBLK)
#define SISFIFO(m)  (((m) & S_IFMT) == S_IFIFO)
#define SISLNK(m)   (((m) & S_IFMT) == S_IFLNK)
#define SISSOCK(m)  (((m) & S_IFMT) == S_IFSOCK)

//#define S_IRWXU         0000700         /* mask for user */
//#define S_IRUSR         0000400         /* R for user */
//#define S_IWUSR         0000200         /* W for user */
//#define S_IXUSR         0000100         /* X for user */
//
//#define SIRUSR(m)   (((m) & S_IRWXU) == S_IRUSR)
//#define SIWUSR(m)   (((m) & S_IRWXU) == S_IWUSR)
//#define SIXUSR(m)   (((m) & S_IRWXU) == S_IXUSR)
//
//#define S_IRWXG         0000070         /* RWX mask for group */
//#define S_IRGRP         0000040         /* R for group */
//#define S_IWGRP         0000020         /* W for group */
//#define S_IXGRP         0000010         /* X for group */
//
//#define SIRGRP(m)   (((m) & S_IRWXG) == S_IRGRP)
//#define SIWGRP(m)   (((m) & S_IRWXG) == S_IWGRP)
//#define SIXGRP(m)   (((m) & S_IRWXG) == S_IXGRP)


typedef struct s_main {
    char **file_arr;
    char **dir_arr;
    char **err_arr;

    int f_count;
    int d_count;
    int e_count;

    int R;
    int S;
    int l;
    int a;
    int A;
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
    int rec_dir_c;

    int max_f_size;   // длинна файла
    int max_uid_size;  // длинна user id
    int max_gid_size;  // длинна group id
    int max_link_size;
    int max_byte_size;
} t_dir;

char *mx_abs_path(char *name);
void mx_dirwalk(t_main *ls, char *file_name);
void mx_get_permissions(t_dir *m_ls, int i);
void mx_init_m_struct(char *dir, t_dir *m_ls);
void mx_print_long(t_dir *m_ls, t_main *ls);
void mx_sort_struct(t_dir *m_ls);
void mx_get_ugid(t_dir *m_ls, int i);
void mx_print_acl(char *file);
void mx_print_specific_time(time_t t);
void mx_print_total_blocks(t_dir *m_ls);
char mx_get_type_file(struct stat buf, char a);
void mx_array_filling(t_main *ls, char** argv, int argc);
void mx_filling_array_dir(t_main *ls);
void mx_array_count(t_main *ls, char** argv, int argc);
void mx_clean_struct(t_dir *m_ls);
void mx_standard_format(t_main *ls, t_dir *m_ls);
void mx_read_args(int argc, char **argv, t_main *ls);
void mx_print_arg_name(t_main *ls, t_dir *m_ls);
void mx_print_recursive(t_main *ls, t_dir *m_ls);

#endif
