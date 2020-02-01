#include "uls.h"

int main(int argc, char *argv[]) {
    (void)argc;
    t_dir *m_ls = (t_dir *)malloc(sizeof(t_dir));
    char *file_name = mx_abs_path(argv[1]);

    mx_init_m_struct(file_name, m_ls);
    mx_dirwalk(m_ls, file_name);
    mx_sort_struct(m_ls);
    mx_print_long(m_ls);
//    system("leaks -q uls");
    return 0;
}
