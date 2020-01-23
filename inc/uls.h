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

typedef struct s_file {
    struct stat stat;
    char  *perm;
    char *file_name;
    char *linkname;
} t_file;

typedef struct s_main {
    t_file *pointer;
    int file_count;
    char *path;

} t_main;

void mx_dirwalk(t_main *m_ls, char *dir);
void mx_get_permissions(t_main *m_ls, int i);
void mx_init_m_struct(char *dir, t_main *m_ls);



#endif
