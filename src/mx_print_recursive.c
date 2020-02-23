#include "uls.h"

void mx_print_recursive(t_main *ls, t_dir *m_ls) {
    char **rec_arr = (char **)malloc((m_ls->rec_dir_c + 1) * sizeof(char *));

    for (int i = 0, j = 0; i < m_ls->file_count; i++) {
        if (SISDIR(m_ls->pointer[i].stat.st_mode) && (m_ls->pointer[i].file_name[0] != '.')) {
            rec_arr[j] = m_ls->pointer[i].linkname;
            j++;
        }
    }
    rec_arr[m_ls->rec_dir_c] = NULL;

    if (m_ls->rec_dir_c > 0) {
        for (int i = 0; rec_arr[i] != NULL; i++) {
            mx_dirwalk(ls, mx_abs_path(rec_arr[i]));
        }
    }
}
