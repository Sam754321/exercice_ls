#include "libft.h"

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmpnext;

	if(alst && *alst && (del))
	{
		tmpnext = *alst;
		while(tmpnext)
		{
			*alst = tmpnext;
			tmpnext = tmpnext->next;
			del((*alst)->content,(*alst)->content_size);
			free(*alst);
			*alst =NULL;
		}
	}
}