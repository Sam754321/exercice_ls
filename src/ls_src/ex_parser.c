#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

static void ex_del_free_array(char **arr)
{
    char **tmp_arr;

    tmp_arr = arr;
    if(arr && !(*arr))
    {
        free(arr);
        return;
    }
    while (tmp_arr && *tmp_arr)
    {
        free(*tmp_arr);
        *tmp_arr = NULL;
        tmp_arr++;
    }
    arr ? free(arr) : 0;
}

static void pars_in(t_parsed* st_pars, char **tmp_arr)
{
    char *tmp;

    tmp = NULL;
    if(st_pars && tmp_arr && ex_str_array_len((const char**)tmp_arr) == 5)
    {   
        st_pars->msg = ft_strdup(tmp_arr[0]);
        st_pars->success = ft_strdup(tmp_arr[1]);
        st_pars->error = ft_strdup(tmp_arr[2]);
        tmp = ft_strtrim_char((const char*)tmp_arr[3], "|");
        tmp ? 0 : ex_print_error_exit("ERROR_ARRAY");
        st_pars->array = ft_strsplit(tmp , '#');
        st_pars->correct = ft_atoi(tmp_arr[4]);
        tmp ? free(tmp) : 0;
    }
    else
        ex_print_error_exit("ERROR_PARSING_IN");
}

static t_parsed *str_to_st_pars(char *str)
{
    t_parsed *ret_st_pars;
    char **tmp_arr;

    ret_st_pars = NULL;
    tmp_arr = NULL;
    if(str)
    {
        (ret_st_pars = (t_parsed*)malloc(sizeof(t_parsed))) ? 0 : ex_print_error_exit("Erreur_Allocation");
        (tmp_arr = ft_strsplit(str,',')) ? 0 : ex_print_error_exit("Erreur_Split_T_Parsed");
        pars_in(ret_st_pars, tmp_arr);
        if(!ret_st_pars->msg || !ret_st_pars->success || !ret_st_pars->error || !ret_st_pars->array )
                ex_print_error_exit("ERROR_PARSING_IN");
        tmp_arr ? ex_del_free_array(tmp_arr) : 0;
    }
    return ret_st_pars;
}


tt_list *ex_parser(char *path)
{
    tt_list *ret_lst;
    char **arr_st_pars;
    char **arr_iter_pars;
    char *str_entry;

    ret_lst = NULL;
    if(!path)
        ex_print_error_exit("Erreur_Path");
    str_entry = ex_get_file(path);
    (arr_st_pars = ft_strsplit(str_entry, ';')) ? 0 : ex_print_error_exit("Erreur_Pars_tt_list");
    arr_iter_pars = arr_st_pars;
    free(str_entry);
    while(arr_iter_pars && *arr_iter_pars)
    {
        if(!(ret_lst))
            ret_lst = ex_listnew(str_to_st_pars(*arr_iter_pars));
        else
            ex_list_push_back(&ret_lst, ex_listnew(str_to_st_pars(*arr_iter_pars)));
        arr_iter_pars++;
    }
    if(arr_st_pars)
    {
        arr_iter_pars = arr_st_pars;
        while(arr_iter_pars && *arr_iter_pars)
        {
            free(*arr_iter_pars);
            arr_iter_pars++;
        }
        free(arr_st_pars);
    }
    return ret_lst;
}