#include "libft.h"

size_t ft_strlen(const char *s)
{
	char t;
	size_t i;
	t = '\0';
	i =0;
	if (!s)
		return i;
	while (t != s[i])
	{
			i++;
	}
	return i;
}