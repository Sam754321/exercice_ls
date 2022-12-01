#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

void ex_list_del_one(tt_list *element, void (*del)(void *))
{
    void *content;
    if (element)
    {
        content = (void *)element->content;
        if (content && del)
        {
            del(content);
        }
        free(element);
        element = NULL;
    }
}