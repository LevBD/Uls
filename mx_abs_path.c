#include "uls.h"

char *mx_abs_path(char *name) {
    size_t len_path = mx_strlen(name);
    size_t len_name = mx_strlen(name);
    char *p;
    if (name[0] != '.')
        len_path += 2;
    if (name[len_name - 1] != '/')
        len_path++;
    p = mx_strnew(len_path);
    if (name[0] != '.')
        mx_strcpy(p, "./");
    mx_strcpy(p, name);
    if (name [len_name - 1] != '/')
        p[len_path - 1] = '/';
    return p;
}
