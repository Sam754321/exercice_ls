#include "libft.h"

t_list * ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	t_list *lstmp;
	t_list *tmpnext;
	t_list *tmpstart;
	t_list *save;
	
	tmpnext = lst;
	if(lst && (f))
	{
		if(!(lstmp = f(tmpnext)))
				return NULL;
		lstmp = ft_lstnew(lstmp->content,lstmp->content_size);
		if(!lstmp)
				return NULL;
		tmpstart =lstmp;
		tmpnext =  tmpnext->next;
		save = tmpstart;
		while(tmpnext)
		{
			if(!(lstmp = f(tmpnext)))
				return NULL;
			save->next = ft_lstnew(lstmp->content,lstmp->content_size);
			if(!save->next)
				return NULL;
			save = save->next;
			tmpnext =  tmpnext->next;
		}
	}
	return tmpstart;
}