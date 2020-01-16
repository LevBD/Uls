#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    int len_str;
    char *n_str;

    if (s1 == NULL && s2 == NULL)
        return NULL;
    else if (s1 == NULL)
        return mx_strdup(s2);
    else if (s2 == NULL)
        return mx_strdup(s1);
    else {
        len_str = mx_strlen(s1) + mx_strlen(s2);
        n_str = mx_strnew(len_str);
        mx_strcpy(n_str, s1);
        mx_strcpy(n_str + mx_strlen(s1), s2);
    }
    return n_str;
}

