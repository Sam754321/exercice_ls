#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

void ex_list_push_front(tt_list **head, tt_list *new)
{
    if(head && new)
    {
        if((*head) && (*head) != new)
        {
            new->next = (*head);
            (*head) = new;
        }
        else if(!(*head))
        {
            (*head) = new;
        }
    }
}