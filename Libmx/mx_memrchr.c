#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *d = (unsigned char*)s + mx_strlen(s) - 1;

    while (n--) {
        if (*d != (unsigned char)c)
            d--;
        else
            return d;
    }
    return NULL;
}

