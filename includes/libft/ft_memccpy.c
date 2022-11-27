#include "libft.h"
void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	   if (dest!=NULL && src!=NULL && src!=dest)
	   {
    	char *d = dest;
    	const char *s = src;
    	size_t i;

    		for (i = 0 ; i<n ; i++)
    		{	
    			*d = *s;
    			s++;
    			if (c == *d)
    				return d+1;
    			d++;
    		}
		}
		return NULL;
}