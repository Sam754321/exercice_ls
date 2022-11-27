#include"libft.h"

char * ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *st;
	size_t i;
	
	st = (char*)malloc(len+1);
	i =0;
	if(st == NULL)
		return NULL;
	if(start == 0 && len == 0 && s)
		return st;
	if(s)
	{	
		while(i<len && s[start+i] != '\0')
		{
			st[i] = s[start+i];
			i++;
		}
		st[i]= '\0';
		return st;
	}
	return NULL;
}