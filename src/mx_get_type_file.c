#include "uls.h"

char mx_get_type_file(struct stat buf, char a) {
    if (S_ISREG(buf.st_mode))
        a = '-';
    else if (S_ISDIR(buf.st_mode))
        a = 'd';
    else if (S_ISCHR(buf.st_mode))
        a = 'c';
    else if (S_ISBLK(buf.st_mode))
        a = 'b';
    else if (S_ISFIFO(buf.st_mode))
        a = 'p';
    else if (S_ISLNK(buf.st_mode))
        a = 'l';
    else if (S_ISSOCK(buf.st_mode))
        a = 's';
    return a;
}
