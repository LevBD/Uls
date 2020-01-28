#include "uls.h"

static void print_specific_time(time_t t);

void mx_print_long(t_main *m_ls) {
    for (int i = 0; i < m_ls->file_count; ++i) {
        mx_printstr(m_ls->pointer[i].perm);
        mx_printstr("  ");
        mx_printint(m_ls->pointer[i].stat.st_nlink);
        mx_printstr("  ");
        mx_printint(m_ls->pointer[i].stat.st_uid);
        mx_printstr("  ");
        mx_printstr(m_ls->pointer[i].user_name);
        mx_printstr("  ");
        mx_printstr(m_ls->pointer[i].group_name);
        mx_printstr("  ");
        mx_printint(m_ls->pointer[i].stat.st_size);
        mx_printstr("  ");
        print_specific_time(m_ls->pointer[i].stat.st_mtimespec.tv_sec);
        mx_printstr("  ");
        mx_printstr(m_ls->pointer[i].file_name);
        mx_printstr("\n");
    }
}

static void print_specific_time(time_t t) {
    char *temp_time = ctime(&t);
    char *result = mx_strnew(12);
    time_t now = time(NULL);
    if ((now - 15778463) > t || now < t) {
        result = mx_strncpy(result, temp_time + 4, 6);
        mx_strcpy(result + 6, "  ");
        mx_strncpy(result + 8, temp_time + 20, 4);
        mx_printstr(result);
        free(result);
    } else {
        result = mx_strncpy(result, temp_time + 4, 12);
        mx_printstr(result);
        free(result);
    }
}
