#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int,char *))
{
	unsigned int i;
	size_t l;

	i = 0;
	l = ft_strlen(s);
	if(s && (f))
	{	
		while (i < l)
		{
			f(i,&s[i]);
			i++;
		}
	}
}