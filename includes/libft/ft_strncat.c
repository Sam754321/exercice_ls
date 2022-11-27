#include "libft.h"

char *ft_strncat(char *dest, const char *src,size_t n)
{
	size_t ld;
	size_t i;
	
	ld = ft_strlen(dest);
	if(dest < src)
	{
		for(i=0; i<n && src[i] != '\0';i++)		
			dest[ld+i] = src[i];
		dest[ld+i] = '\0';	
		return dest;
	}
	else if(dest > src)
	{
		for(i=n-1; i>0;i--)		
			dest[ld+i] = src[i];
		dest[ld] = src[0];
		dest[ld+n] = '\0';	
		return dest;
	}
	return dest;
}
