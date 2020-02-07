#include "uls.h"

void mx_clean_struct(t_dir *m_ls) {
    free(m_ls->pointer->linkname);
    free(m_ls->pointer->file_name);
    free(m_ls->pointer->group_name);
    free(m_ls->pointer->perm);
    free(m_ls->pointer->user_name);
}
