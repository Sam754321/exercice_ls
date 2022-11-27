#include "libft.h"

void ft_strclr(char *s)
{
	size_t l;
	size_t i;

	i=0;
	l = ft_strlen(s);

	while (i<l)
	{
		s[i] = '\0';
		i++;
	}
}