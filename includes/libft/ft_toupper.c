#include "libft.h"

int ft_toupper(int c)
{
	if ((c>=-128 && c<-1 )|| (c>=0 && c<=255 ))
	 	c = (unsigned char)c;
	if ( c <= 'z' && c >= 'a')
	{
		c -= 32;
		return c;
	}
	return c;
}
		