#include "libmx.h"

int mx_strncmp(const char *str1, const char *str2, int len_str2) {
    for (int i = 0; i < len_str2; i++) {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
    }
    return *str1 - *str2;
}
