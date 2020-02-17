#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int len = mx_strlen(s1);

    mx_strcpy(s1 + len, s2);
    return s1;
}

