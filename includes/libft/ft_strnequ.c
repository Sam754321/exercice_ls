#include "libft.h"

int ft_strnequ(char const *s1, char const *s2,size_t n)
{
	size_t i;

	i=0;
	if(s1== NULL || s2 == NULL)
		return 0;
    if(s1 && s2 && n)
    {
		while((s1[i] != '\0'|| s2[i] != '\0') && s1[i] == s2[i])
		{
			i++;
			if(i == n-1)
				break;
		}
		if(s1[i] == s2[i])
				return 1;
		else if(s1[i] != s2[i])
				return 0;
	}
	return 1;
}