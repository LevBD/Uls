#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *n_node = *list;

    if(!list)
        return;
    while (n_node->next != NULL)
        n_node = n_node->next;
    n_node->next = malloc(sizeof(t_list));
    if (n_node == 0)
    	return;
    n_node->next->data = data;
    n_node->next->next = NULL;
}

