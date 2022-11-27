#include "libft.h"

void ft_bzero(void *s,size_t n)
{
    if (s != NULL)
	{
    	size_t i = 0;
    	while (n > i)
    	{
    		((char*)s)[i]=0;
    		i++;
    	}
    }
}

