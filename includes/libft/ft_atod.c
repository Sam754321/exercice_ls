#include "libft.h"

static int check_before_digit(const char *nptr, int *i, double *s)
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

double ft_atod(const char *nptr)
{
    double r;
    int i;
    int j;
    double s;
    double t;

    j = 0;
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
        for (j = i; ft_isdigit(nptr[j]); j++)
            ;
        while (j > i)
        {
            t = ((t + (nptr[j - 1] - 48)) / 10);
            j--;
        }
    }
    return (r + t) * s;
}