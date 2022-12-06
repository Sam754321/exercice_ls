#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

static void print_flag_l(t_content *content_lst, char *str2)
{
    char *str;

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

static void print_lst_dir(tt_list *tmp_next_lst, long *flag)
{
    t_content *content_lst;
    char *str2;

    while (tmp_next_lst)
    {
        content_lst = tmp_next_lst->content;
        str2 = ft_strrchr(content_lst->path, '/');
        if (check_flag_up('l', flag))
        {
            if (check_flag_up('a', flag))
                print_flag_l(content_lst, str2);
            else if (str2[1] != '.')
                print_flag_l(content_lst, str2);
        }
        else if (check_flag_up('a', flag))
        {
            ft_putstr(&str2[1]);
            ft_putstr("\t");
        }
        else if (str2[1] != '.')
        {
            ft_putstr(&str2[1]);
            ft_putstr("\t");
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

static void flag_recurse_list(t_content *content_lst, long *long_flag)
{
    char *str;

    if (check_flag_up('R', long_flag))
    {
        str = ft_strrchr(content_lst->path, '/');
        if ((content_lst->type == 'd' && str[1] != '.'))
            ex_print_dir_rec(content_lst->path, *long_flag);
        else if (check_flag_up('a', long_flag))
        {
            if (content_lst->type == 'd' && str[1] == '.' && str[2] != 0 && str[2] != '.')
                ex_print_dir_rec(content_lst->path, *long_flag);
        }
    }
}

static char *print_path_error(char *path)
{
    char *ret_str;

    if (!(ret_str = ft_strjoin(path, "' ")))
        exit(1);
    return ret_str;
}

void ex_print_dir_rec(char *path, long long_flag)
{
    tt_list *lst;
    tt_list *tmp_next_lst;
    t_content *content_lst;
    char *error_path;

    if (path)
    {
        if (!(lst = ex_get_dir_list(path, &long_flag)))
        {
            ft_putstr_fd("ls: impossible d'ouvrir le répertoire '", 2);
            error_path = print_path_error(path);
            perror(error_path);
            free(error_path);
            return;
        }
        ft_putstr(path);
        ft_putstr(":\n");
        tmp_next_lst = lst;
        print_lst_dir(tmp_next_lst, &long_flag);
        ft_putstr("\n");
        tmp_next_lst = lst;
        while (tmp_next_lst)
        {
            content_lst = tmp_next_lst->content;
            flag_recurse_list(content_lst, &long_flag);
            tmp_next_lst = tmp_next_lst->next;
        }
        ex_list_del_all(&lst, free_del_content);
    }
}