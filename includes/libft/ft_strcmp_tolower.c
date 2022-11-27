#include "libft.h"

int ft_strcmp_tolower(const char *s1, const char *s2)
{
	int i;
	int t;
	int j ;
	char a;
	char b;

	a = 0;
	b = 0;
	j = 0;
	i = 0;
	t = 0;
	while (s1[i] != '\0' || s2[j] != '\0')
	{	
		a = ft_tolower((unsigned int)s1[i]);
		b = ft_tolower((unsigned int)s2[j]);
		if (a  == b)
		{
				i++;
				j++;
		}
		else  
		{
			t = (a - b);
			return (unsigned int)t;
		}
	}
	return (unsigned int)s1[i] - (unsigned int)s2[j];
}