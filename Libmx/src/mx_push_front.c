#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *n_node = NULL;

    if (!list)
        return ;
    n_node = (void*)malloc(sizeof(t_list));
    if (n_node == 0)
    	return;
    n_node->data = data;
    n_node->next = *list;
    *list = n_node;
}

