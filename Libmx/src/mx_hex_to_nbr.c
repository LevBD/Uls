#include "libmx.h"

static int m_strlen(const char *c);
static double m_pow(double n, unsigned int pow);
static unsigned int hex_number(char c);

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
    int len = m_strlen(hex);

    for (int t = 0, i = len -1; t < len; t++, i--) {
        result += hex_number(hex[t]) * m_pow(16, i);
    }
    return result;
}

static int m_strlen(const char *c) {
    int i = 0;

    while (c[i] != '\0') {
        i++;
    }
    return i;
}

static double m_pow(double n, unsigned int pow) {
    if (pow == 0) {
        return 1;
    }
    else if (pow > 0) {
        n = n * m_pow(n, pow -1);
        return n;
    }
    else
        return 0;
}

static unsigned int hex_number(char c) {
    if (c >= '0' && c <= '9')
        return c - 48;
    else if (c >= 'A' && c <= 'F')
        return c - 55;
    else if (c >= 'a' && c <= 'f')
        return c - 87;
    return c;
}

