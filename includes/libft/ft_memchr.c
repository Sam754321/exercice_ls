#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *t;
	size_t i;
	i=0;
	t = (unsigned char*)s;
	if(!s)
		return NULL;
	while(i<n)
	{
		if(t[i] == (unsigned char)c)
			return (void*)&t[i];
		i++;
	}
	return NULL;
}