#include "libft.h"

int ft_cmp_char_str(char c, char *str)
{
    int i;

    i = 0;
    if(!c || !str)
        return -1;
    while(str[i])
    {
        if(str[i] == c)
            return 0;
        i++;
    }
    return 1;
}