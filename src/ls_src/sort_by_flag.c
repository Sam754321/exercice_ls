#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

int sort_by_flag(void *iter, void *end, long *option)
{
        t_content *it;
        t_content *en;
        static int flag_up = -1;

        if(flag_up == -1)
            flag_up = check_flag_up('t', option);
        it = (t_content*)iter;
        en = (t_content*)end;
        if(flag_up)
        {
                if(ft_strcmp(it->path, en->path) <= 0 )
                        return 1;
                else return 0;
        }
        return 0;
                
}