#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *temp = mx_strtrim(str);
    int j = 0;
    char *res;

    for (int i = 0; temp[i] != '\0'; i++) {
        if (mx_isspace(temp[i])) {
            temp[j] = ' ';
            j++;
            while (mx_isspace(temp[i]))
                i++;
        }
        temp[j] = temp[i];
        j++;
    }
    res = mx_strnew(j);
    res = mx_strncpy(res, temp, j);
    mx_strdel(&temp);
    return res;
}

