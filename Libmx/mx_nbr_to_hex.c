#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int i = 0;
    unsigned long r = nbr;
    char *hex;

    if (r > 0)
        for (; r > 0; r /= 16, ++i);
    else {
        hex = mx_strnew(1);
        hex[0] = '0';
        return hex;
    }
    hex = mx_strnew(i);
    for (; nbr > 0; i--) {
        if (nbr % 16 < 10)
            hex[i - 1] = nbr % 16 + 48;
        else
            hex[i - 1] = nbr % 16 + 87;
            nbr /= 16;
    }
    return hex;
}

