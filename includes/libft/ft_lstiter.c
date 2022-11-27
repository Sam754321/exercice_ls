#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list * tmpnext;
	
	if(lst && (f))
	{
		tmpnext = lst;
		while(tmpnext)
		{
			f(tmpnext);
			tmpnext = tmpnext->next;
		}
	}
}
