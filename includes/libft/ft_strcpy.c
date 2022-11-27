#include "libft.h"

char *ft_strcpy(char *dest, const char *src)
{
	size_t i;
	size_t l;

	l = ft_strlen(src);
	if(l == 0)
		return dest;
	if(dest < src)
	{
		for(i=0;i <= l ; i++)
		{
			dest[i] = src[i];
		}
		return dest;
	}
	else if(dest > src)
	{
		for(i=l;i > 0 ; i--)
		{
			dest[i] = src[i];
		}
		dest[0] = src[0];
		return dest;
	}
	return dest;
}
