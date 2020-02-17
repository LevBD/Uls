#include "uls.h"

void mx_fill_arr_file(t_main *ls) {
    int i = 0;

    for (i = 0; ls->file_arr[i] != NULL; i++) {
        mx_printstr(ls->file_arr[i]);
        mx_printstr("\n");
    }
}
