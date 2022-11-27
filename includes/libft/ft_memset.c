#include "libft.h"

void *ft_memset(void *s,int c,size_t n)
{
	char * t;
	
	t = (char *)s;
	if(n !=0 && s)
	{	
	    while (n--)
	    {
	    	*t = c;
	    	t++;
	    }
	}
    return s;
}

