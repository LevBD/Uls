#include "uls.h"

static void mx_init_m_stract(char *dir, t_main *m_ls);

int main(int argc, char **argv) {
    (void)argc;
    t_main *m_ls;
    m_ls = (t_main *)malloc(sizeof(t_main));
    mx_init_m_stract(argv[1], m_ls);
    mx_dirwalk(m_ls,argv[1]);
    return 0;
}

static void mx_init_m_stract(char *dir, t_main *m_ls) {
    struct dirent *dp;
    DIR *dfd;
    int size = 0;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: не открыть %sn", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL)
        size++;
    closedir(dfd);
    t_file *file_arr = (t_file*)malloc(sizeof(t_file) * size);
    m_ls->pointer = file_arr;
    m_ls->file_count = size;
}
