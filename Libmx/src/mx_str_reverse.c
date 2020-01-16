#include "libmx.h"

void mx_str_reverse(char *s) {
    int size = mx_strlen(s);
    int mid = (size - 1) / 2;

    if (!s)
        return;
    for (int i = 0; i <= mid; i++, size--)
        mx_swap_char(&s[i], &s[size - 1]);
}

