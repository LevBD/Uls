#include "libmx.h"

char *mx_replace_substr(const char *str,
    const char *sub, const char *replace) {
    char *n;
    int c;
    int p = 0;
    int p_n = 0;
    int i = 0;

    if (!sub || !str || !replace)
        return NULL;
    c = mx_count_substr(str, sub);
    if (c == 0)
        return (char*)str;
    n = mx_strnew(mx_strlen(str) - c * mx_strlen(sub) + c * mx_strlen(replace));
    for (int j = 0; j < c; j++) {
        i = mx_get_substr_index((str + p), sub);
        mx_strncpy((n + p_n), (str + p), i);
        mx_strcat((n), replace);
        p_n += i + mx_strlen(replace);
        p += i + mx_strlen(sub);
    }
    return n;
}

