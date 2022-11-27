#include "libft.h"

void ft_striter(char *s, void (*f)(char *))
{
	size_t i;
	size_t l;
	
	l = ft_strlen(s);
	i=0;
	if(s && (f))
	{
		while (i<l)
		{
			f(&s[i]);
			i++;
		}
	}
}