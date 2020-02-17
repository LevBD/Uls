#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int size;
    int count;
    int word;

    if (str == NULL)
        return -1;
    size = mx_strlen(str);
    count = 0;
    word = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] != c && word == 0) {
            word = 1;
            count++;
        }
        if (str[i] == c)
            word = 0;
    }
    return count;
}

