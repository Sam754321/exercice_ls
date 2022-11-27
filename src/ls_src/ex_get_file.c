#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

static void check_end_str(char *str)
{
	size_t len;

	len = 0;
	if (str)
	{
		len = ft_strlen(str);	
		ft_isspace(str[len-1]) ? str[len-1] = 0 : 0;
		ft_isspace(str[len-2]) ? str[len-2] = 0 : 0;
	}
}

static char *mallo_bufer_read(int siz)
{
	char *retstr;
	if(!(retstr = (char*)malloc(siz)))
		ex_print_error_exit("ERROR MALLOC");
	ft_memset(retstr,11,0);
	return retstr;
}

static char *ret_cpy_join_read(char *tempstr, char *tmp_join_str)
{
	char *retstr;

	retstr = NULL;
	if(tmp_join_str)
				{
					retstr = ft_strjoin(tmp_join_str,tempstr);
					free(tmp_join_str);
					check_end_str(retstr);
				}
				else
				{
					retstr = ft_strdup(tempstr);
					check_end_str(retstr);
				}
	return retstr;
}

static void cpy_join_read(char **retstr, char **tempstr, char **tmp_join_str)
{
	if(!(*tmp_join_str))
	{
		*tmp_join_str = ft_strdup(*tempstr);
		*retstr = *tmp_join_str;
	}
	else if(*(tmp_join_str))
	{
		*retstr = ft_strjoin(*tmp_join_str, *tempstr);
		free(*tmp_join_str);
		*tmp_join_str = *retstr;
	}
}

char *ex_get_file(const char *path)
{
	int f;
	int nc;
	char *retstr;
	char *tempstr;
	char *tmp_join_str;

	retstr = NULL;
	tmp_join_str = NULL;
	nc = 1;
	if((f = open(path, O_RDONLY)) == -1)
			ex_print_error_exit("ERROR IN OPEN EX_GET_FILE");
	tempstr = mallo_bufer_read(10001);
	while(nc != 0)
	{
			if((nc = read(f,tempstr,10000))  == -1)
			{
				free(tempstr);
				f ? close(f) : 0;
				ex_print_error_exit("ERROR IN READ EX_GET_FILE");
			}
			tempstr[nc] = '\0';
			if(nc < 10000)
			{
				retstr = ret_cpy_join_read(tempstr, tmp_join_str);
				free(tempstr);
				f ? close(f) : 0;
				return retstr;
			}
			else if(nc == 10000)
				cpy_join_read(&retstr, &tempstr, &tmp_join_str);
	}
	tempstr ? free(tempstr) : 0;
	f ? close(f) : 0;
	return retstr;
}