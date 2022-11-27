#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

static char *str_check_rwx(struct stat *info)
{
    char *ret;
	int i;
    
	if(!(ret = ((char *)malloc(sizeof(char) * 11))))
        exit(-1);
	for(i = 0; i < 10 ; i++)
		ret[i] = '-';
	ret[10] = '\0';
    switch (info->st_mode & S_IFMT) {
    case S_IFBLK:  ret[0] = 'b';     break;
    case S_IFCHR:  ret[0] = 'c';     break;
    case S_IFDIR:  ret[0] = 'd';     break;
    case S_IFIFO:  ret[0] = 'f';     break;
    case S_IFLNK:  ret[0] = 'l';     break;
    case S_IFREG:  ret[0] = '-';     break;
    case S_IFSOCK: ret[0] = 's';     break;
    default:       ret[0] = '-';     break;
    }
info->st_mode & S_IRUSR ? ret[1] = 'r' : 0 ;
info->st_mode & S_IWUSR ? ret[2] = 'w' : 0 ;
info->st_mode & S_IXUSR ? ret[3] = 'x' : 0 ;
info->st_mode & S_IRGRP ? ret[4] = 'r' : 0 ;
info->st_mode & S_IWGRP ? ret[5] = 'w' : 0 ;
info->st_mode & S_IXGRP ? ret[6] = 'x' : 0 ;
info->st_mode & S_IROTH ? ret[7] = 'r' : 0 ;
info->st_mode & S_IWOTH ? ret[8] = 'w' : 0 ;
info->st_mode & S_IXOTH ? ret[9] = 'x' : 0 ;
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

    if(!(ret = ft_strdup(getpwuid(info->st_uid)->pw_name)))
        ret = "nobo";
    return ret;
}

static char *str_gid(struct stat *info)
{
    char *ret;
    if(!(ret = ft_strdup(getgrgid(info->st_gid)->gr_name)))
        ret = "nobo";
    return ret;
}

static char *str_time(struct stat *info)
{
    char *ret;

    ret = ft_strsub(ctime(&info->st_ctime), 4, 12);
    return ret;
}

char **array_str_stat_info(struct stat *info)
{
    char **ret_array;
    ret_array = NULL;
    if(info)
    {
         if(!(ret_array = ((char**)malloc(6 * sizeof(char*)))))
            exit(-1);
        ret_array[0] = str_check_rwx(info) ;
        ret_array[1] = str_link_nb(info);
        ret_array[2] = str_uid(info);
        ret_array[3] = str_gid(info);
        ret_array[4] = str_time(info);
        ret_array[5] = 0;
    }
    return ret_array;
}