#include "libft.h"

char *ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t l;
	
	l = ft_strlen(src);
	if(n <= l)
	{
		for(i=0;i<n;i++)
			dest[i] = src[i];
		return dest;		
	}
	else if(n > l)
	{
		for(i=0;i<l;i++)
			dest[i] = src[i];
		for(;i<n;i++)
			dest[i] = '\0';
		return dest;
	}
	return dest;
}
