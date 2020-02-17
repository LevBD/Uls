#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *s = (unsigned char *)dst;
    unsigned char *a = (unsigned char *)src;

    while (n--)
        *(s++) = *(a++);
    return dst;
}

