#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char ***p = arr;
    char **pp = *arr;

    if (arr == NULL)
        return;
    while (**p != NULL) {
        mx_strdel(*p);
        (*p)++;
    }
    free(pp);
    *arr = NULL;
}

