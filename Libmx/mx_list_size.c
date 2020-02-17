#include "libmx.h"

int mx_list_size(t_list *list) {
    int count = 0;
    t_list *n_node = list;

    while (n_node != NULL) {
        n_node = n_node->next;
        count++;
    }
    return count;
}

