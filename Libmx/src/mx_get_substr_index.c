#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    char *s;

    if (!str || !sub) {
        return -2;
    }
    s = mx_strstr(str, sub);
    if (s == NULL) {
        return -1;
    }
    return s - str;
}

