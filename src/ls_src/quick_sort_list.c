#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

static tt_list *pivot_point(tt_list *start, tt_list *end, long *flag)
{
    tt_list *pivot;
    tt_list *iter_lst_pivot;
    t_content *tmp_content;

    pivot = start;
    iter_lst_pivot = start;
    while (iter_lst_pivot != NULL && iter_lst_pivot != end)
    {
        if (sort_by_flag(iter_lst_pivot->content, end->content, flag) > 0)
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

void quick_sort(tt_list *head, tt_list *last, long *flag)
{
    tt_list *pivot;

    if (head == last)
        return;
    pivot = pivot_point(head, last, flag);
    if (pivot != NULL && pivot->next != NULL)
        quick_sort(pivot->next, last, flag);
    if (pivot != NULL && head != pivot)
        quick_sort(head, pivot, flag);
}
