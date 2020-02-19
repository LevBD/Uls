#include "uls.h"

int main(int argc, char *argv[]) {
    (void)argc;
    t_main *ls = (t_main *)malloc(sizeof(t_main));

    mx_array_count(ls, argv, argc);
    ls->err_arr = (char**)malloc(sizeof(char*)*ls->e_count + 1);
    ls->dir_arr = (char**)malloc(sizeof(char*)*ls->d_count + 1);
    ls->file_arr = (char**)malloc(sizeof(char*)*ls->f_count + 1);
    mx_array_filling(ls, argv, argc);
    mx_filling_array_dir(ls);
//    system("leaks -q uls");
    return 0;
}
