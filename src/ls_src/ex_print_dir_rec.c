#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

static void print_lst_dir(tt_list *tmp_next_lst)
{
    t_content *content_lst;
    char *str;
    char *str2;

    while (tmp_next_lst)
    {
        content_lst = tmp_next_lst->content;
        str2 = ft_strrchr(content_lst->path, '/');
        if ((str2[1] != '.' && str2[2] != '.') || (str2[1] == '.' && str2[2] != '.' && str2[2] != 0) || (str2[1] != '.' && str2[2] == '.'))
        {
            ft_putstr(content_lst->stat_array_info[0]);
            ft_putstr(" ");
            ft_putstr(content_lst->stat_array_info[1]);
            ft_putstr(" ");
            ft_putstr(content_lst->stat_array_info[2]);
            ft_putstr(" ");
            ft_putstr(content_lst->stat_array_info[3]);
            ft_putstr(" ");
            str = ft_ltoa(content_lst->len);
            ft_putstr(str);
            ft_putstr(" ");
            ft_putstr(content_lst->stat_array_info[4]);
            ft_putstr(" ");
            ft_putstr(&str2[1]);
            ft_putstr("\n");
            free(str);
        }
        tmp_next_lst = tmp_next_lst->next;
    }
}

static void free_del_content(void *tmp_lst)
{
    t_content *lst;

    lst = (t_content *)tmp_lst;
    if (lst)
    {
        free(lst->path);
        lst->path = NULL;
        lst->len = 0;
        lst->type = 0;
        free(lst);
        tmp_lst = NULL;
        lst = NULL;
    }
}

void ex_print_dir_rec(char *path, char *flag)
{
    tt_list *lst;
    tt_list *tmp_next_lst;
    t_content *content_lst;
    char *str;
    static long long_flag = 0;
    static int first_set_flag = -3;

    if (path)
    {
        if (first_set_flag == -3)
            first_set_flag = set_flag_up(flag, &long_flag);
        if (first_set_flag != 2 && first_set_flag != 0)
        {
            perror("Xrtl flag miss");
            exit(-1);
        }
        if (!(lst = ex_get_dir_list(path, &long_flag)))
        {
            ft_putstr("ls: impossible d'ouvrir le répertoire");
            perror(path);
            return;
        }
        ft_putstr(path);
        ft_putstr(":\n");
        tmp_next_lst = lst;
        print_lst_dir(tmp_next_lst);
        ft_putstr("\n");
        tmp_next_lst = lst;
        while (tmp_next_lst)
        {
            content_lst = tmp_next_lst->content;
            str = ft_strrchr(content_lst->path, '/');
            if (content_lst->type == 'd' && str[0] != '.' && str[1] != '.')
                ex_print_dir_rec(content_lst->path, flag);
            tmp_next_lst = tmp_next_lst->next;
        }
        ex_list_del_all(&lst, free_del_content);
    }
}