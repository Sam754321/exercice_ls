#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t i;
	char *str1;
	size_t l;
	
	i = 0;
	str1 = (char*)haystack;
	l =  ft_strlen(needle);
	if (l == 0 )
		return str1;

	while (str1[i] != '\0' && i+l <= n)
	{   
		if (str1[i] == needle[0] && ft_strncmp(&str1[i],&needle[0],l)==0)
			return &str1[i];
		i++;
	}
	return NULL;
}