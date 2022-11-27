#include "libft.h"

void ft_putstr_color_fd(int fdstr,int fdcolor,char* str,char* color)
{
	write(fdcolor,color,ft_strlen(color));
	write(fdstr,str,ft_strlen(str));
	write(fdcolor,COLOR_RESET,ft_strlen(COLOR_RESET));	
}