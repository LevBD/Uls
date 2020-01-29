#include "uls.h"

void mx_print_total_blocks(t_main *m_ls) {
    blkcnt_t total = 0;
    for (int i = 0; i < m_ls->file_count; i++)
        total += m_ls->pointer[i].stat.st_blocks;
    mx_printstr("total ");
    mx_printint(total);
    mx_printstr("\n");
}
