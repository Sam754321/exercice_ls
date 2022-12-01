#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	char *t;
	size_t j;
	size_t i;

	i = 0;
	j = ft_strlen(s);
	t = (char *)s;
	if (!s || !t)
		return NULL;

	while (i <= j)
	{
		if (t[i] == c)
			return &t[i];

		i++;
	}
	return NULL;
}