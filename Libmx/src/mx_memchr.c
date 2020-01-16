#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *d = (unsigned char*)s;

    while (n--) {
        if (*d != (unsigned char)c)
            d++;
        else
            return d;
    }
    return 0;
}

