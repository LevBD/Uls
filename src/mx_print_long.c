#include "uls.h"

void mx_print_long(t_main *m_ls) {
    for (int i = 0; i < m_ls->file_count; ++i) {
        mx_printstr(m_ls->pointer[i].perm);
        mx_printstr("\t");
        mx_printstr(m_ls->pointer[i].file_name);
        mx_printstr("\n");
    }
}
