#include "uls.h"

//static void get_max_len(t_main *m_ls, int i);
static void print_spaces(int number);

void mx_print_long(t_main *m_ls) {
    mx_print_total_blocks(m_ls);
    for (int i = 0; i < m_ls->file_count; i++) {
        mx_printstr(m_ls->pointer[i].perm);
        mx_print_acl(m_ls, i);
        print_spaces(m_ls->max_link_size + 1 - mx_strlen(m_ls->pointer[i].linkname));
        mx_printint(m_ls->pointer[i].stat.st_nlink);
        print_spaces(1);
        mx_printstr(m_ls->pointer[i].user_name);
        print_spaces(m_ls->max_uid_size + 2 - mx_strlen(m_ls->pointer[i].user_name));
        mx_printstr(m_ls->pointer[i].group_name);
        print_spaces(m_ls->max_gid_size - mx_strlen(m_ls->pointer[i].group_name));
        mx_printint(m_ls->pointer[i].stat.st_size);
        mx_printstr("  ");
        mx_print_specific_time(m_ls->pointer[i].stat.st_mtimespec.tv_sec);
        mx_printstr("  ");
        mx_printstr(m_ls->pointer[i].file_name);
        mx_printstr("\n");
    }
}

//static void get_max_len(t_main *m_ls, int i) {
//    if (mx_strlen(m_ls->pointer[i].file_name) > m_ls->max_f_size)
//        m_ls->max_f_size = mx_strlen(m_ls->pointer[i].file_name);
//    if (mx_strlen(m_ls->pointer[i].user_name) > m_ls->max_uid_size)
//        m_ls->max_uid_size = mx_strlen(m_ls->pointer[i].user_name);
//    if (mx_strlen(m_ls->pointer[i].group_name) > m_ls->max_gid_size)
//        m_ls->max_gid_size = mx_strlen(m_ls->pointer[i].group_name);
//    if (mx_strlen(m_ls->pointer[i].linkname) > m_ls->max_link_size)
//        m_ls->max_link_size = mx_strlen(m_ls->pointer[i].linkname);
//    if (mx_strlen(mx_itoa(m_ls->pointer[i].stat.st_size)) > m_ls->max_byte_size)
//        m_ls->max_byte_size = mx_strlen(mx_itoa(m_ls->pointer[i].stat.st_size));
//}

static void print_spaces(int number) {
    for (int i = 0; i < number; i++) {
        mx_printchar(' ');
    }
}
