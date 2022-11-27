#include "libft.h"

char *ft_strcat(char *dest, const char *src)
{
	size_t ls;
	size_t ld;
	size_t i;
	
	ls = ft_strlen(src);
	ld = ft_strlen(dest);
	if(dest < src)
	{
		for(i=0; i<ls;i++)		
			dest[ld+i] = src[i];
		dest[ld+i] = '\0';	
		return dest;
	}
	else if(dest > src)
	{
		for(i=ls; i>0;i--)		
			dest[ld+i] = src[i];
		dest[ld] = src[0];
		dest[ld+ls] = '\0';	
		return dest;
	}
	return dest;
}
