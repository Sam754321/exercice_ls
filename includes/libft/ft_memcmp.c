
#include <libft.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char u1;
	unsigned char u2;

	if ( n == 0)
		return (0);
	while (n--)
	{
		u1 = *((unsigned char*)s1);
		u2 = *((unsigned char*)s2);
		if (u1 != u2 )
			return (u1 - u2);
		if (n)
		{
			s1++;
			s2++;
		}
	}
	return (0);
}