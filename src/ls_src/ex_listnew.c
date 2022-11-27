#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

tt_list *ex_listnew(void *content)
{
    tt_list *retlist;

    if(!(retlist = (tt_list*)malloc(sizeof(tt_list))))
            return NULL;
    retlist->content = content;
    retlist->next = NULL;

    return retlist;

}