#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

tt_list *ex_list_last(tt_list *list)
{
    tt_list *retlist;

    retlist = NULL;
    if(list)
    {
        retlist = list;
        while(retlist->next)
        {
            retlist = retlist->next;
        }
    }
    return retlist;
}