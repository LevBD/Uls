#include "libmx.h"

static int file_len(const char *file);

char *mx_file_to_str(const char *file) {
    int f = open(file, O_RDONLY);
    int count;
    int size;
    char *newstr;

    if (f == -1) {
        close(f);
        return NULL;
    }
    count = 0;
    size = file_len(file);
    if (size == 0)
        return NULL;
    newstr = mx_strnew(size);
    count = read(f, newstr, size);
    close(f);
    return newstr;
}

static int file_len(const char *file) {
    int f = open(file, O_RDONLY);
    int size = 0;
    int len = 0;
    char buf;

    size = read(f, &buf, 1);
    while (size > 0) {
        size = read(f, &buf, 1);
        len++;
    }
    close(f);
    return len;
}

