#include "libft.h"

char *ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int l;
	i = 0;

	char *str1;
	str1 = (char*)haystack;
	l =  ft_strlen(needle);
	if (l == 0 )
		return str1;
	while (str1[i])
	{   
		if (str1[i] == needle[0] && ft_strncmp(&str1[i],&needle[0],l)==0)
			return &str1[i];
		i++;
	}
	return NULL;
}