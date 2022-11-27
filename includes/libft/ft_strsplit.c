#include "libft.h"

static int nbstr(const char *s,char c)
{
	int i;
	int j;

	i=0;
	j =0;
	if(!s)
		return 0;
	while(s[i])
	{
		if(s[i]== c && s[i+1] != c && s[i+1] !='\0' )
			j++;
		i++;
	}
	if (s[0] != c)
		j++;
	return j;
}

static char * fstr(const char * s,char c,int i)
{
	int j;

	j=0;
	while(s[i+j]!= c && s[i+j]!='\0')
		j++;
	return ft_strsub(s,i,j);
}

char ** ft_strsplit(char const *s, char c)
{
	int i;
	int j;
	char ** rarr;
	int nbs;

	i=0;
	j=0;
	rarr =NULL;
	nbs = nbstr(s,c);
	if(!s)
		return NULL;
	if (nbs ==0)
	{
		rarr = (char**)malloc(sizeof(rarr)*(1));
		if(rarr == NULL)
		 	return NULL;
		rarr[0]=NULL;
		return rarr;
	}
	if(nbs)
		rarr = (char**)malloc(sizeof(char**)*(nbs+1));
	if(!rarr)
		return NULL;
	while(s[i])
	{
		if(s[i]== c )
			i++;
		else if (s[i] != c && s[i] != '\0' )
		{	
			rarr[j] = fstr(s,c,i);
			j++;
			while(s[i]!= c && s[i] != '\0')
				i++;
		}
	}
	rarr[j] = NULL;
	return rarr;
}