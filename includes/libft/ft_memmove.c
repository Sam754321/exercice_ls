#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;
	char *d;
	const char *s;
	
	s = src;
	d = dest;
	if(!n || !src ||!dest)
		return dest;
	if (dest < src )
	{
		for(i=0;i<n;i++)
			d[i] = s[i];
	}
	else if (dest>src)
	{
		for(i=n-1;i>0;i--)
			d[i] = s[i];
		d[0] = s[0];
	}
	return dest;
}
