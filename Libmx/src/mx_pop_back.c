#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *temp = NULL;

    if (head && *head && (*head)->next) {
        temp = *head;
        while (temp->next->next)
            temp = temp->next;

        if (malloc_size(temp->data))
            free(temp->next->data);
        
        free(temp->next);
        temp->next = NULL;
    }
    else if (head && *head) {
        free(*head);
        *head = NULL;
    }
}
