#include "libmx.h"

char *mx_strtrim(const char *str) {
    char *new_str;
    int size_new;
    int size = mx_strlen(str);
    int counter1 = 0;
    int counter2 = 0;

    if (!str)
        return NULL;
    for (int i = 0; mx_isspace(str[i]); i++)
        counter1++;
    for (int i = size - 1 ; mx_isspace(str[i]); i--)
        counter2++;
    size_new = size - counter1 - counter2;
    new_str = mx_strncpy(mx_strnew(size_new), (str + counter1), size_new);
    return new_str;
}

