#include "uls.h"

void mx_print_arg_name(t_main *ls, t_dir *m_ls) {
    if (ls->d_count > 1) {
        mx_printstr(m_ls->path);
        mx_printstr(":");
        mx_printstr("\n");
    }
}
