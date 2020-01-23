#include "uls.h"

int main(int argc, char **argv) {
    (void)argc;
    t_main *m_ls;
    m_ls = (t_main *)malloc(sizeof(t_main));
    mx_init_m_struct(argv[1], m_ls);
    mx_dirwalk(m_ls,argv[1]);
//    system("leaks -q uls");
    return 0;
}
