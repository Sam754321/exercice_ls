#include"libft.h"

char * ft_strnew(size_t size)
{
	char * t;
	size_t i;
	
	t = (char*)malloc(size);
	i=0;
	if (t == NULL)
		return NULL;

	while(i<size)
	{
		t[i] ='\0';
		i++;
	}
	return t;
}