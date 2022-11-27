#include "ft_printf.h"

char convchr(const char *s)
{
	char ret;
	int i;

	ret = NULL;

	while (s[i] == 's' || s[i] == 'S' || s[i] == 'p' || s[i] == 'd'
		   || s[i] == 'D' || s[i] == 'i' || s[i] == 'o' || s[i] == 'O'
		    || s[i] == 'u' || s[i] == 'U' || s[i] == 'x' || s[i] == 'X'
		     || s[i] == 'c' || s[i] == 'C' )
	{
		ret = s[i];
		i++;
	}
	return ret; 
}