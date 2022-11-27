#include "libft.h"

char * ft_strmap(char const *s, char (*f)(char))
{
	size_t i;
	size_t l;
	char *st;
	i=0;
	l = ft_strlen(s);
	if(s && (f))
	{
		if(!(st = (char*)malloc(l)))
			return NULL;
		while(i<l)
	{
		st[i] = f(s[i]);
		i++;
	}
		st[i] = '\0';
		return st;
	}
	return NULL;
}