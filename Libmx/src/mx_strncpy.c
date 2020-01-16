#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int len_src = mx_strlen(src);

    for (int i = 0; i < len; i++) {
        if (i < len_src)
        dst[i] = src[i];
    else
        dst[i] = '\0';
    }
    return dst;
}

