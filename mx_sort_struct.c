#include "uls.h"

void mx_sort_struct(t_dir *m_ls) {
    t_file temp;
    int size = m_ls->file_count;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (mx_strcmp(m_ls->pointer[j].file_name, m_ls->pointer[j + 1].file_name) > 0) {
                temp = m_ls->pointer[j];
                m_ls->pointer[j] = m_ls->pointer[j + 1];
                m_ls->pointer[j + 1] = temp;
            }
        }
    }
}
