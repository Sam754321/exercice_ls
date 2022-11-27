#include"libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ls; 
	size_t ld;
	size_t i;
	size_t j;

	ls = ft_strlen(src);
	ld = ft_strlen(dst);
	j = ls;
	if(dst < src)
	{
		for(i=0; i<size -ld && src[i] != '\0';i++)		
			dst[ld+i] = src[i];
		dst[ld+i] = '\0';
	}
	else if(dst > src)
	{
		for(i=ls+ld; i>=ld;i--,j--)		
			dst[i] = src[j];
		dst[ld+ls] = '\0';
				
	}
	return ld+ls;
}