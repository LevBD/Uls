#include "uls.h"

static int count_dir(char** argv, int argc);
static int count_file(char** argv, int argc);
static int count_error(char** argv, int argc);

void mx_array_count(t_main *ls, char** argv, int argc) {
    ls->e_count = count_error(argv, argc);
    ls->d_count = count_dir(argv, argc);
    ls->f_count = count_file(argv, argc);
}

static int count_dir(char** argv, int argc) {
    int count = 0;
    char c = '\0';
    struct stat buf;

    for(int i = 1; i < argc; i++) {
        lstat(argv[i], &buf);
        c = mx_get_type_file(buf, c);
        if (c == 'd')
            count++;
    }
    return count;
}

static int count_file(char** argv, int argc) {
    int count = 0;
    char c = '\0';
    struct stat buf;
    int status = 0;

    for(int i = 1; i < argc; i++) {
        status = lstat(argv[i], &buf);
        c = mx_get_type_file(buf, c);
        if (c != 'd' && status != -1)
            count++;
    }
    return count;
}

static int count_error(char** argv, int argc) {
    int count = 0;
    struct stat buf;
    for(int i = 1; i < argc; i++) {
        if(lstat(argv[i], &buf) == -1)
            count++;
    }
    return count;
}
