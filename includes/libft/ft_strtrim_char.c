#include "libft.h"

static int checkset(char c, char *set)
{
    int i;

    i = 0;
    while(set[i])
    {
        if(c == set[i])
            return 1;
        i++;
    }
    return 0;
}
// retourne une string malloc jusqu'au char demander;
char *ft_strtrim_char(const char * str, char *set)
{
    char *retstr;
    int start;
    int end;

    start = 0;
    end = ft_strlen((char*)str);
    retstr = NULL;
    if(str && set)
    {
        while(checkset(str[start], set))
            start++;
        if(start < (end - 1))
        {
            while(checkset(str[end-1], set))
                end--;
        }
        retstr = ft_strsub(str, start, ( end - start )); 
    }
    return retstr;
} 