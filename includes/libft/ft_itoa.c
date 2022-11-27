#include "libft.h"

static long puis(long n)
{
	long x;
	
	x=1;
	if(!n)
		return 0;
	while (n)
	{
		x = x*10;
		n--;
	}
	return x;
}

char * ft_itoa(int n)
{
	char *t;
	long i;
	long ti;
	long tj;
	long tk;
	long tl;

	tl = (long)n;
	tk =0;
	ti = (long)n;
	tj = 0;
	i=0;
	while (!(ti >=0 && ti <=10) || !(ti <=0 && ti >=-10))
	{	
		ti = ti/10;
		tk++;
	}

	if(tl<0)
	{	
		tl = tl*(-1);
		t = ft_strnew(sizeof(char) * tk + 2);
		if(t==NULL)
			return NULL;
		i=1;
		t[0]='-';
	}
	else if(tl == 0)
	{
		t = ft_strnew(sizeof(char) * 2);
		if(t==NULL)
			return NULL;
		t[0]='0';
		t[1]='\0';
		return t;
	}
	else 
	{
		t = ft_strnew(sizeof(char) * tk + 1);
		if(t==NULL)
			return NULL;
	}

	while (tk>1)
	{
		tj = 0;
		tj = tl / puis(tk-1);
		t[i] = tj+'0';
		tl -= tj *puis(tk-1);
		tk--;
		i++;
	}	
	t[i] = tl+'0';
	return t;
}