#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

static int check_before_digit(const char *nptr, int *i, int *s)
{
    int j;

    j = *i;
    if (ft_strlen(nptr) == 0)
        return 0;
    while (ft_isspace(nptr[j]))
        j++;
    if (nptr[j] == '+')
        j++;
    else if (nptr[j] == '-')
    {
        *s = -1;
        j++;
    }
    *i = j;
    return 1;
}

int atoi_check_version(const char *nptr, int *len)
{
    int r;
    int i;
    int s;
    int t;

    t = 0;
    r = 0;
    i = 0;
    s = 1;
    if (!check_before_digit(nptr, &i, &s))
        return 0;
    while (ft_isdigit(nptr[i]))
    {
        r = r * 10 + (nptr[i] - 48);
        i++;
    }
    if ((nptr[i] == '.' || nptr[i] == ',') && ft_isdigit(nptr[i + 1]))
    {
        i++;
        while (ft_isdigit(nptr[i]))
        {
            r = r * 10 + (nptr[i] - 48);
            i++;
        }
    }
    *len = i;
    return (r + t) * s;
}