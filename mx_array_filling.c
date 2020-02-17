#include "uls.h"

void mx_array_filling(t_main *ls, char** argv, int argc) {
    struct stat buf;
    int f = 0;
    int d = 0;
    int e = 0;
    char c = '\0';
    int j = 0;
    int status;

    for(int i = 1; i < argc; i++) {
        status = lstat(argv[i], &buf);
        if (argv[i][j] != '-') {
            if (status == -1) {
                ls->err_arr[e] = argv[i];
                e++;
            }
            c = mx_get_type_file(buf, c);
            if (c == 'd') {
                ls->dir_arr[d] = argv[i];
                d++;
            }
            if (c != 'd' && status != -1) {
                ls->file_arr[f] = argv[i];
                f++;
            }
        }
    }
    ls->file_arr[f] = NULL;
    ls->dir_arr[d] = NULL;
    ls->err_arr[e] = NULL;
}
