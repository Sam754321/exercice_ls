#include "libft.h"

char * ft_strjoin(char const *s1, char const *s2)
{
	size_t i;
	size_t ls1;
	size_t ls2;
	char * st;

	i =0;
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	if(!s1 && !s2)
		return NULL;
	st = (char*)malloc(sizeof(st)*(ls1+ls2+1));
	if(st == NULL)
		return NULL;
	while(i<ls1)
	{
		st[i]= s1[i];
		i++;
	}
	while(i<ls2+ls1)
	{
		st[i] = s2[i-ls1];
		i++;
	}
	st[i]= '\0';
	return st;
}