#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

tt_list *pivot_point( tt_list *start, tt_list *end)
{
    tt_list *pivot;
    tt_list *iter_lst_pivot;
    t_content *tmp_content;
    t_content *tmp1;
    t_content *tmp2;

    pivot = start;
    iter_lst_pivot = start;
    
    while(iter_lst_pivot != NULL && iter_lst_pivot != end)
    {
        tmp1 = (t_content*)iter_lst_pivot->content;
        tmp2 = (t_content*)end->content; 
        if(tmp1->len < tmp2->len)
        {
            pivot = start;
            tmp_content = start->content;
            start->content = iter_lst_pivot->content;
            iter_lst_pivot->content = tmp_content;
            start = start->next;
        }
        iter_lst_pivot = iter_lst_pivot->next;
    }
    tmp_content = start->content;
    start->content = end->content;
    end->content = tmp_content;
    return pivot;
}

void quick_sort(tt_list *head, tt_list *last)
{
    tt_list *pivot;

    if(head == last)
        return;
    pivot = pivot_point(head, last);
    if(pivot != NULL && pivot->next != NULL)
        quick_sort(pivot->next, last);
    if(pivot != NULL && head != pivot)
        quick_sort(head, pivot);
}
