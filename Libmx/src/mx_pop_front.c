#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *n_node = NULL;

    if (!head || !(*head))
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    n_node = *head;
    *head = (*head)->next;

    if (malloc_size(n_node->data))
        free(n_node->data);
    free(n_node);
}

