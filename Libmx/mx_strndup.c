#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    size_t len;
    char *newstr;

    if (s1 == NULL)
        return NULL;
    len = mx_strlen(s1);
    if (len < n)
        n = len;
    newstr = mx_strnew(n);
    return mx_strncpy(newstr, s1, n);
}

