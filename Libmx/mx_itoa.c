#include "libmx.h"

char *mx_itoa(int number) {
    int size = 0;
    long r = number;
    char *str;

    if (number < 0) {
        size++;
        r *= -1;
    }
    if (number == 0)
        return mx_strdup("0");
    for (long w = r; w > 0; w /= 10, size++);
    str = mx_strnew(size);
    if (number < 0)
        str[0] = '-';
    for (; r > 0; r /= 10, size--)
        str[size - 1] = r % 10 + '0';
    return str;
}

