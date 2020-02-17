#include "libmx.h"

#include <stdio.h>

char *mx_strstr(const char *haystack, const char *needle) {
    int len_haystack = mx_strlen(haystack);
    int len_needle = mx_strlen(needle);

    if (needle == NULL)
        return (char *)haystack;
    for (int i = 0; i < len_haystack; i++, haystack++) {
        if (mx_strncmp(haystack, needle, len_needle) == 0)
            return (char *)haystack;
    }
    return NULL;
}

