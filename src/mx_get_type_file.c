#include "uls.h"

char mx_get_type_file(struct stat buf, char a) {
    if (SISREG(buf.st_mode))
        a = '-';
    else if (SISDIR(buf.st_mode))
        a = 'd';
    else if (SISCHR(buf.st_mode))
        a = 'c';
    else if (SISBLK(buf.st_mode))
        a = 'b';
    else if (SISFIFO(buf.st_mode))
        a = 'p';
    else if (SISLNK(buf.st_mode))
        a = 'l';
    else if (SISSOCK(buf.st_mode))
        a = 's';
    return a;
}
