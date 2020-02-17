#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, 
				const void *little, size_t little_len) {
    const char *count;
    const char *const m_index = (const char*)big + big_len - little_len;

    if (big_len < little_len || big_len == 0 || little_len == 0)
        return NULL;
    for (count = (const char*)big; count <= m_index; count++) {
        if ((mx_memcmp(count, (const char*)little, little_len)) == 0)
        return (void*)count;
    }
    return NULL;
}

