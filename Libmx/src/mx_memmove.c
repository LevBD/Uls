#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *gap = (char*)malloc(len);

    mx_memcpy(gap,(const char*)src, len);
    mx_memcpy(dst,(const char*)gap, len);
    free(gap);
    return dst;
}

