#include "libmx.h"

char *mx_strdup(const char *str) {
    char *strnew = mx_strnew(mx_strlen(str));

    if (strnew == NULL)
        return NULL;
    return strnew ? mx_strcpy(strnew, str) : NULL;
}

