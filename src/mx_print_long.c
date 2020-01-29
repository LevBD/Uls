#include "uls.h"

void mx_print_long(t_main *m_ls) {
    mx_print_total_blocks(m_ls);
    for (int i = 0; i < m_ls->file_count; i++) {
        mx_printstr(m_ls->pointer[i].perm);
        mx_print_acl(m_ls, i);
        mx_printstr("  ");
        mx_printint(m_ls->pointer[i].stat.st_nlink);
        mx_printstr("  ");
        mx_printstr(m_ls->pointer[i].user_name);
        mx_printstr("  ");
        mx_printstr(m_ls->pointer[i].group_name);
        mx_printstr("  ");
        mx_printint(m_ls->pointer[i].stat.st_size);
        mx_printstr("  ");
        mx_print_specific_time(m_ls->pointer[i].stat.st_mtimespec.tv_sec);
        mx_printstr("  ");
        mx_printstr(m_ls->pointer[i].file_name);
        mx_printstr("\n");
    }
}
