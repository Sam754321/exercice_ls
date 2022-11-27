#include "libft.h"

void * ft_memalloc(size_t size)
{
	char *r;
	size_t i;
	i = 0;
	r = (char*)malloc(size);

	if(r == NULL) 
		return NULL;

	while( i < size)
	{
		r[i] = 0;
		i++;
	}
	return (void*)r;	
}