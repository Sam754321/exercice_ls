#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

void ex_print_error_exit(char *str)
{
    char *ret;

    ret = "Error";
    if(str)
        ret = str;
    perror("");
    ft_putstr(ret);
    ft_putchar('\n');
    exit(1);
}