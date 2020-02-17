#include "uls.h"

void mx_filling_array_dir(t_main *ls) {
    int i = 0;

    for (i = 0; ls->dir_arr[i] != NULL; i++)
        mx_dirwalk(ls, ls->dir_arr[i]);
}
