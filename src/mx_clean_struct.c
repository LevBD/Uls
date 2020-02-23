#include "uls.h"

static void clean_struct_s_file(t_file *file) {
    mx_strdel(&file->file_name);
    mx_strdel(&file->group_name);
    mx_strdel(&file->perm);
    mx_strdel(&file->user_name);
    mx_strdel(&file->linkname);
}

void mx_clean_struct(t_dir *m_ls) {
        free(m_ls->path);
    for (int i = 0; i < m_ls->file_count; i++)
            clean_struct_s_file(&m_ls->pointer[i]);
}
