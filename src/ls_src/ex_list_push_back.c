#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

void ex_list_push_back(tt_list **head, tt_list *new)
{
    tt_list *tmplist;

    if(head && new)
    {
        if(!(*head))
            (*head) = new;
        else if(*head && !((*head)->next) && (*head) != new )
            (*head)->next = new;
        else if((*head)->next)
        {
            tmplist = (*head);
            while(tmplist->next)
            {
                tmplist = tmplist->next;
            }
            tmplist->next = new;
        } 
    }
}