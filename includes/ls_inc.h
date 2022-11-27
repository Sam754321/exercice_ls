#ifndef LS_INC
#define LS_INC

#include <stdio.h>
#include <stddef.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <wchar.h>
#include <pwd.h>
#include "libft/includes/libft.h"
#include <grp.h>

 # define SET_OPTS					1
 # define XOR_OPTS					2
 # define SUPR_OPTS					4
 # define LAST_OPTS					8

typedef struct ss_list
{
	void 	*content;
	size_t 	content_size;
	struct 	ss_list 	*next;			
}				tt_list;	 			


typedef struct s_test
{
    int val;
    char *str;
}              t_test;

typedef struct          s_content
{
    char *path;
    size_t len;
    unsigned char type;
    time_t time;
    char **stat_array_info;
}                       t_content;

typedef struct s_parsed
{
    char *msg;
    char *error;
    char *success;
    char **array;
    int correct;
}              t_parsed;

tt_list *ex_get_dir_list(char *path);
void ex_list_del_all(tt_list **head, void (*del)(void *));
void ex_list_del_one(tt_list *element, void (*del)(void *));
tt_list *ex_list_last(tt_list *list);
void ex_list_push_back(tt_list **head, tt_list *new);
void ex_list_push_front(tt_list **head, tt_list *new);
tt_list *ex_listnew(void *content);
void ex_print_error_exit(char *str);
size_t ex_str_array_len(const char **arr);
 tt_list *pivot_point( tt_list *start,  tt_list *end);
char **array_str_stat_info(struct stat *info);
void ex_print_dir_rec(char *path);
char *ex_get_file(const char *path);



#endif