#include "libft.h"

char *ft_strdup(const char *s)
{
	size_t l;
	char *cst;
	char* tmp;
	
	l = ft_strlen(s);
	cst = (char*)malloc(l+1);
	tmp = cst;
	if(cst == NULL)
		return NULL;
	while (*s)
	{
		*cst=*s;
		 cst++;
		 s++;
	}
	*cst = '\0';
	return tmp;
}