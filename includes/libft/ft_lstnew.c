#include "libft.h"

t_list * ft_lstnew(void const *content, size_t content_size)
{
	void * tmp;
	t_list *lst;
	
	lst = (t_list*)malloc(sizeof(t_list*));
	if(lst == NULL)
		return NULL;
	if(!content)
	{
		lst->content = NULL;
		lst->content_size = 0;
		lst->next = NULL;
		return lst;
	}
	tmp = ft_memalloc(content_size);
	if(!tmp)
		return NULL;
	ft_memcpy(tmp,content,content_size);
	lst->content = tmp;
	lst->content_size = content_size;
	lst->next = NULL;
	return lst;
}