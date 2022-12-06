#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

static int convert_alpha_num(int car)
{
    int ret;

    ret = -1;
    if (car >= 97 && car <= 122)
        ret = car - 97;
    else if (car >= 65 && car <= 90)
        ret = (car - 65) + 26;
    return ret;
}

int check_flag_up(char c, long *options)
{
    long flag;
    int decal_byt;

    flag = 0;
    decal_byt = convert_alpha_num(c);
    flag |= 1L << decal_byt;
    if (flag & *options)
        return 1;
    return 0;
}