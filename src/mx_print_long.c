#include "uls.h"

static void print_spaces(int number) {
    for (int i = 0; i < number; i++) {
        mx_printchar(' ');
    }
}

static void print_linkname(t_dir *m_ls, int i) {
    char link[255];
    int size = 0;
    if (!m_ls->pointer[i].linkname)
        return;
    size = readlink(m_ls->pointer[i].linkname, link, 255);
    link[size] = '\0';
    mx_printstr(" -> ");
    mx_printstr(link);
}

static void print_l(t_dir *m_ls, int i, char *link, char *b_size) {
    mx_printstr(m_ls->pointer[i].perm);
    mx_print_acl(m_ls->pointer[i].linkname);
    link = mx_itoa(m_ls->pointer[i].stat.st_nlink);
    print_spaces(m_ls->max_link_size + 1 - mx_strlen(link));
    mx_printint(m_ls->pointer[i].stat.st_nlink);
    print_spaces(1);
    mx_printstr(m_ls->pointer[i].user_name);
    print_spaces(m_ls->max_uid_size + 2 - mx_strlen(m_ls->pointer[i].user_name));
    mx_printstr(m_ls->pointer[i].group_name);
    print_spaces(m_ls->max_gid_size + 2 - mx_strlen(m_ls->pointer[i].group_name));
    b_size = mx_itoa(m_ls->pointer[i].stat.st_size);
    print_spaces(m_ls->max_byte_size - (mx_strlen(b_size)));
    mx_printint(m_ls->pointer[i].stat.st_size);
    print_spaces(1);
    mx_print_specific_time(m_ls->pointer[i].stat.st_mtimespec.tv_sec);
    print_spaces(1);
    mx_printstr(m_ls->pointer[i].file_name);
    if (SISLNK(m_ls->pointer[i].stat.st_mode))
        print_linkname(m_ls, i);
    mx_printstr("\n");
}

void mx_print_long(t_dir *m_ls, t_main *ls) {
    char *link = NULL;
    char *b_size = NULL;

    mx_print_arg_name(ls,m_ls);
    mx_print_total_blocks(m_ls);
    for (int i = 0; i < m_ls->file_count; i++) {
        if (mx_strcmp(m_ls->pointer[i].file_name, ".") 
            && mx_strcmp(m_ls->pointer[i].file_name, "..")
            && m_ls->pointer[i].file_name[0] != '.') {
            print_l(m_ls, i, link, b_size);
            free(link);
            free(b_size);
        }
    }
}
