#ifndef ULS_H
#define ULS_H

#include <string.h>
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

//typedef struct stat {
//    mode_t     st_mode;
//} m_stat;

void dirwalk(char *dir);

#endif
