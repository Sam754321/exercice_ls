#include "libft.h"

char * ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
	unsigned int i;
	char *st;
	size_t l;

	i = 0;
	l = ft_strlen(s);
	if (s && (f))
	{
		if (l == 0)
		{
			if (!(st = (char*)malloc(1)))
				return NULL;
			st[0] = '\0';
			return st;
		}
		if (!(st = (char*)malloc(l)))
			return NULL;
		while(i<l)
		{
			st[i] = f(i,s[i]);
			i++;
		}
		st[i] = '\0';
		return st;
	}
	return NULL;
}