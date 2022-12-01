#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

static int sort_by_name(t_content *iter, t_content *end)
{
        int ret_cmp;

        ret_cmp = ft_strcmp(iter->path, end->path);
        if (ret_cmp < 0)
                return 1;
        else
                return 0;
}

static int sort_by_size(t_content *iter, t_content *end)
{
        if (iter->len < end->len)
                return 1;
        else if (iter->len == end->len)
                return sort_by_name(iter, end);
        else
                return 0;
}

static int sort_by_ext(t_content *iter, t_content *end)
{
        char *tmp_iter;
        char *tmp_end;

        tmp_iter = ft_strrchr(iter->path, '.');
        tmp_end = ft_strrchr(end->path, '.');
        printf("AVANT%s  ___  %s -----%s_____%s\n", tmp_iter, tmp_end, iter->path, end->path);

        if ((!tmp_iter && !tmp_end) || (tmp_iter[0] == '.' && tmp_iter[1] == 0) || tmp_iter[-1] == '.' || (tmp_end[0] == '.' && tmp_end[1] == 0) || tmp_end[-1] == '.')
                return sort_by_name(iter, end);
        else if (tmp_iter && !tmp_end)
                return 0;
        else if (!tmp_iter && tmp_end)
                return 1;
        else if (tmp_iter && tmp_end)
        {
                printf("%s  ___  %s -----%s_____%s\n", tmp_iter, tmp_end, iter->path, end->path);
                return ft_strcmp(tmp_iter, tmp_end);
        }
        else
                return sort_by_name(iter, end);
}

static int sort_by_m_time(t_content *iter, t_content *end)
{
        if (iter->mtime > end->mtime)
                return 1;
        else if (iter->mtime == end->mtime)
                return sort_by_name(iter, end);
        else
                return 0;
}

static int sort_by_c_time(t_content *iter, t_content *end)
{
        if (iter->ctime > end->ctime)
                return 1;
        else if (iter->ctime == end->ctime)
                return sort_by_name(iter, end);
        else
                return 0;
}

static int sort_by_a_time(t_content *iter, t_content *end)
{
        if (iter->atime > end->atime)
                return 1;
        else if (iter->atime == end->atime)
                return sort_by_name(iter, end);
        else
                return 0;
}

int sort_by_flag(void *iter, void *end, long *flag)
{
        t_content *it;
        t_content *en;
        int control_sort;

        if (*flag & (*flag & 32))
        {
                en = (t_content *)iter;
                it = (t_content *)end;
        }
        else
        {
                it = (t_content *)iter;
                en = (t_content *)end;
        }
        if (*flag & 1)
        {
                control_sort = sort_by_size(it, en);
                if (control_sort > 0)
                        return 1;
        }
        else if (*flag & 2)
        {
                if (sort_by_m_time(it, en))
                        return 1;
        }
        else if (*flag & 4)
        {
                if (sort_by_c_time(it, en))
                        return 1;
        }
        else if (*flag & 8)
        {
                if (sort_by_a_time(it, en))
                        return 1;
        }
        else if (*flag & 16)
        {
                if (sort_by_ext(it, en))
                        return 1;
        }
        else
        {
                if (sort_by_name(it, en))
                        return 1;
        }
        return 0;
}