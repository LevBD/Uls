#include "libmx.h"

int mx_sqrt(int x) {
    if (x > 0) {
        for (unsigned int i = 1; i * i <= (unsigned)x; i++) {
            if (i * i == (unsigned)x)
            return i;
        }
    }
    return 0;
}

