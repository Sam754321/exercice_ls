#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

static int convert_alpha_num(int car)
{
    int ret;

    ret = -1;
    if(car >= 97 && car <= 122 )
        ret = car - 97;
    else if(car >= 65 && car <= 90 )
        ret = (car - 65) + 26;
    return ret;
}

int set_flag_up(char *str, long *options)
{
    int i;
    int j;
    char *list_option;

    list_option = ft_strdup("rRStX");
    i = 1;
    if(!str || !list_option ||!(*str) || !(*list_option))
        return 0;
    else if(str[0] != '-' || (str[0] == '-' && str[1] == '-') )
        return -1;
    else if(str[0] == '-')
    {
        while(str[i])
        {
            j = ft_isalpha(str[i]);
            if(ft_cmp_char_str(str[i], list_option) != 0 && !j)
                return -1;
            else if(j)
                *options |= 1 << convert_alpha_num(str[i]),printf("%ld__option\n",*options);
            i++;
        }
        return 2;
    }
    return (i -1);
}