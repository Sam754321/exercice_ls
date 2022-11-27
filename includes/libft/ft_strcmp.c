#include "libft.h"

int ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int t;

	i = 0;
	t = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{	
		if ((unsigned int)s1[i]  == (unsigned int)s2[i])
			i++;
		else  
		{
			t = (unsigned char)s1[i]  - (unsigned char)s2[i];
			return (unsigned int)t;
		}
	}
	return (unsigned int)s1[i] - (unsigned int)s2[i];
}