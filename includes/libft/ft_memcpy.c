#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	   if (dest != NULL && src != NULL && src != dest){
    	char *d = dest;
    	const char *s = src;

    	while (n--)
    	{
    	    *d = *s;
    	    d++;
    	    s++;
    	}
    }
    return dest;
}

