#include "libft.h"

int ft_atoi(const char *nptr)
{
	int r;
	int i;
	int s;
	
	r = 0;
	i = 0;
	s = 1;
	if(ft_strlen(nptr) == 0)
		return 0;
	while(ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+')
	    i++;
	else if (nptr[i] =='-')
	{
		s = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		r = r * 10 + (nptr[i] - 48);
		i++;
	} 
	return r * s;
}
