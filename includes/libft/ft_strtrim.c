#include "libft.h"

char * ft_strtrim(char const *s)
{
	int i;
	size_t h;
	i = 0;
	h = ft_strlen(s);
	h = h > 0 ? h - 1 : h;
		if(!s)
			return NULL;
		while(s[i]==' ' || s[i]=='\n' || s[i]=='\t' )
			i++;
		while(s[h]==' ' || s[h]=='\n' || s[h]=='\t' )
			h--;
		if((int)h<0)
		    return ft_strsub(s,0,0);
		return ft_strsub(s,i,h-i+1);
}
