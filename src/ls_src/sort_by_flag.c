#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

static int sort_by_name(t_content *iter, t_content *end)
{
        int ret_cmp;

        ret_cmp = ft_strcmp_tolower(iter->path, end->path);
        if (ret_cmp < 0)
                return 1;
        else if (ret_cmp > 0)
                return 0;
        else
                return -1;
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
        int ret_cmp;

        tmp_iter = ft_strrchr(iter->path, '.');
        tmp_end = ft_strrchr(end->path, '.');
        if ((!tmp_iter && !tmp_end))
                return sort_by_name(iter, end);
        else if (tmp_iter && !tmp_end)
                return 1;
        else if (!tmp_iter && tmp_end)
                return 0;
        else if (tmp_iter && tmp_end)
        {
                ret_cmp = ft_strcmp_tolower(tmp_iter, tmp_end);
                if (ret_cmp < 0)
                        return 1;
                else if (ret_cmp == 0)
                        return sort_by_name(iter, end);
                else
                        return 0;
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

static int sort_by_version(char *iter, char *end)
{
        int i;
        double tmp_iter;
        double tmp_end;
        int len;

        len = 0;
        i = 0;
        while (iter[i] != '\0' || end[i] != '\0')
        {
                if (iter[i] == end[i])
                {
                        if ((ft_isdigit(iter[i]) && ft_isdigit(end[i])) || ((iter[i] == '.' || end[i] == '.') && (ft_isdigit(iter[i + 1]) || ft_isdigit(end[i + 1]))))
                        {
                                tmp_iter = atod_check_version(&iter[i], &len);
                                len = 0;
                                tmp_end = atod_check_version(&end[i], &len);
                                if (tmp_iter > tmp_end)
                                        return 1;
                                else if (tmp_iter < tmp_end)
                                        return -1;
                                else
                                        sort_by_version(&iter[i + (len)], &end[i + (len)]);
                        }
                        i++;
                }
                else
                        return iter[i] - end[i];
        }
        return iter[i] - end[i];
}

static void flag_r(t_content **it, t_content **en, void *iter, void *end, long *flag)
{
        if (check_flag_up('r', flag))
        {
                *en = (t_content *)iter;
                *it = (t_content *)end;
        }
        else
        {
                *it = (t_content *)iter;
                *en = (t_content *)end;
        }
}

static int check_all_flag_sort(long *flag)
{

        if (check_flag_up('S', flag))
                return 1;
        else if (check_flag_up('t', flag) && check_flag_up('c', flag))
                return 3;
        else if (check_flag_up('t', flag) && check_flag_up('u', flag))
                return 4;
        else if (check_flag_up('t', flag))
                return 2;
        else if (check_flag_up('X', flag))
                return 5;
        else if (check_flag_up('v', flag))
                return 6;
        else
                return 7;
}

int sort_by_flag(void *iter, void *end, long *flag)
{
        t_content *it;
        t_content *en;
        static int flag_sort_up = 0;

        if (flag_sort_up == 0)
                flag_sort_up = check_all_flag_sort(flag);
        flag_r(&it, &en, iter, end, flag);
        if ((flag_sort_up == 1) && sort_by_size(it, en) > 0)
                return 1;
        else if ((flag_sort_up == 2) && sort_by_m_time(it, en) > 0)
                return 1;
        else if ((flag_sort_up == 3) && sort_by_c_time(it, en) > 0)
                return 1;
        else if ((flag_sort_up == 4) && sort_by_a_time(it, en) > 0)
                return 1;
        else if ((flag_sort_up == 5) && sort_by_ext(it, en) > 0)
                return 1;
        else if ((flag_sort_up == 6) && sort_by_version(it->file_name, en->file_name) < 1)
                return 1;
        else if ((flag_sort_up == 7) && sort_by_name(it, en) > 0)
                return 1;
        return 0;
}