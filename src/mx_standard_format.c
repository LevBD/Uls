#include "uls.h"

static void mx_print_tab(int len_name, int maxlen);
static void print_f_names(t_main *ls, t_dir *m_ls, int maxlen, int win);

void mx_standard_format(t_main *ls,t_dir *m_ls) {
    (void)ls;
    int maxlen = m_ls->max_f_size;
    struct winsize win;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    print_f_names(ls, m_ls, maxlen, win.ws_col);
}

static void print_f_names(t_main *ls, t_dir *m_ls, int maxlen, int win) {
    (void)ls;
    int rows;
    int size = m_ls->file_count;
    int cols = (win / ((8 - (maxlen % 8)) + maxlen));

    if (!m_ls->file_count || !cols || !maxlen)
        return;
    rows = size / cols;
    if (size % cols)
        rows += 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; i + j < size; j += rows) {
            mx_printstr(m_ls->pointer[i + j].file_name);
            if (m_ls->pointer[i + j + 1].file_name && (i + j + rows < size))
                mx_print_tab(mx_strlen(m_ls->pointer[i + j].file_name), maxlen);
        }
        mx_printchar('\n');
    }
}

static void mx_print_tab(int len_name, int maxlen) {
    int count;
    int p;

    for (p = 1; ; p++) {
        if (maxlen < (p * 8 - 1))
            break;
    }
    count = p * 8 - len_name;
    for (int i = 0; i < count; i += 8)
        mx_printchar('\t');
}
