#include "uls.h"

void mx_print_specific_time(time_t t) {
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
