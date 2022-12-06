#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"
static char *str_maloc_rwx()
{
    char *ret;
    int i;

    if (!(ret = ((char *)malloc(sizeof(char) * 11))))
        exit(-1);
    for (i = 0; i < 10; i++)
        ret[i] = '-';
    ret[10] = '\0';
    return ret;
}

static char *str_set_rwx(struct stat *info)
{
    char *ret;

    ret = str_maloc_rwx();
    if ((info->st_mode & S_IFMT) == S_IFBLK)
        ret[0] = 'b';
    else if ((info->st_mode & S_IFMT) == S_IFCHR)
        ret[0] = 'c';
    else if ((info->st_mode & S_IFMT) == S_IFDIR)
        ret[0] = 'd';
    else if ((info->st_mode & S_IFMT) == S_IFIFO)
        ret[0] = 'f';
    else if ((info->st_mode & S_IFMT) == S_IFLNK)
        ret[0] = 'l';
    else if ((info->st_mode & S_IFMT) == S_IFREG)
        ret[0] = '-';
    else if ((info->st_mode & S_IFMT) == S_IFSOCK)
        ret[0] = 's';
    else
        ret[0] = '-';
    info->st_mode &S_IRUSR ? ret[1] = 'r' : 0;
    info->st_mode &S_IWUSR ? ret[2] = 'w' : 0;
    info->st_mode &S_IXUSR ? ret[3] = 'x' : 0;
    info->st_mode &S_IRGRP ? ret[4] = 'r' : 0;
    info->st_mode &S_IWGRP ? ret[5] = 'w' : 0;
    info->st_mode &S_IXGRP ? ret[6] = 'x' : 0;
    info->st_mode &S_IROTH ? ret[7] = 'r' : 0;
    info->st_mode &S_IWOTH ? ret[8] = 'w' : 0;
    info->st_mode &S_IXOTH ? ret[9] = 'x' : 0;
    return ret;
}

static char *str_link_nb(struct stat *info)
{
    char *ret;

    ret = ft_itoa((int)info->st_nlink);
    return ret;
}

static char *str_uid(struct stat *info)
{
    char *ret;

    if (!(ret = ft_strdup(getpwuid(info->st_uid)->pw_name)))
        ret = "ERROR";
    return ret;
}

static char *str_gid(struct stat *info)
{
    char *ret;
    if (!(ret = ft_strdup(getgrgid(info->st_gid)->gr_name)))
        ret = "ERROR";
    return ret;
}

static char *str_time(struct stat *info, int flag)
{
    char *ret;

    char *tmp_join_str;
    char *tmp_join_str2;
    if (flag == 3)
    {
        tmp_join_str = ft_strsub(ctime(&info->st_ctime), 4, 12);
        tmp_join_str2 = ft_strsub(ctime(&info->st_ctime), 19, 5);
        ret = ft_strjoin(tmp_join_str, tmp_join_str2);
    }
    else if (flag == 4)
    {
        tmp_join_str = ft_strsub(ctime(&info->st_atime), 4, 12);
        tmp_join_str2 = ft_strsub(ctime(&info->st_atime), 19, 5);
        ret = ft_strjoin(tmp_join_str, tmp_join_str2);
    }
    else
    {
        tmp_join_str = ft_strsub(ctime(&info->st_mtime), 4, 12);
        tmp_join_str2 = ft_strsub(ctime(&info->st_mtime), 19, 5);
        ret = ft_strjoin(tmp_join_str, tmp_join_str2);
    }
    free(tmp_join_str);
    free(tmp_join_str2);
    return ret;
}

char **array_str_stat_info(struct stat *info, long *flag)
{
    char **ret_array;
    static int stack_flag = 0;

    if (!stack_flag)
    {
        if (check_flag_up('t', flag) && check_flag_up('c', flag))
            stack_flag = 3;
        else if (check_flag_up('t', flag) && check_flag_up('u', flag))
            stack_flag = 4;
        else
            stack_flag = 2;
    }
    ret_array = NULL;
    if (info && *flag)
    {
        if (!(ret_array = ((char **)malloc(6 * sizeof(char *)))))
            exit(-1);
        ret_array[0] = str_set_rwx(info);
        ret_array[1] = str_link_nb(info);
        ret_array[2] = str_uid(info);
        ret_array[3] = str_gid(info);
        ret_array[4] = str_time(info, stack_flag);
        ret_array[5] = 0;
    }
    return ret_array;
}