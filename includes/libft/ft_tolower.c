#include "libft.h"

int ft_tolower(int c)
{
	 if ((c>=-128 && c<-1 )|| (c>=0 && c<=255 ))
	 	c = (unsigned char)c;	
	if ( c <= 'Z' && c >= 'A')
	{
		c += 32;
		return (int)c;
	}
	return (int)c;
}
		