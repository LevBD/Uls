#include "uls.h"

static int is_flag(const char *s) {
    if (*s == '-' && mx_strlen(s) > 1)
        return 1;
    return 0;
}

static void print_err_arg(char *c) {
    mx_printerr("uls: ");
    mx_printerr(c);
    mx_printerr(": ");
    mx_printerr(strerror(errno));
    mx_printerr("\n");
}

static void pars_flags(char *argv,t_main *ls) {
    int i = 1;

    while (argv[i]) {
        if (argv[i] == 'R')
            ls->R = 1;
        else if (argv[i] == 'l')
            ls->l = 1;
        else if (argv[i] == 'a')
            ls->a = 1;
        else if (argv[i] == 'A')
            ls->A = 1;
        else if (argv[i] == 'S')
            ls->S = 1;
        else
            print_err_arg(&argv[i]);
        i++;
    }
}

void mx_read_args(int argc, char **argv, t_main *ls) {
    int i = 1;
    while (i < argc && is_flag(argv[i])) {
        pars_flags(argv[i], ls);
        i++;
    }
}
