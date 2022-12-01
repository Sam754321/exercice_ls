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

#define SET_OPTS 1
#define XOR_OPTS 2
#define SUPR_OPTS 4
#define LAST_OPTS 8

typedef struct ss_list
{
    void *content;
    size_t content_size;
    struct ss_list *next;
} tt_list;

typedef struct s_test
{
    int val;
    char *str;
} t_test;

typedef struct s_content
{
    char *path;
    size_t len;
    unsigned char type;
    dev_t device_id;
    ino_t node_num;
    mode_t file_type;
    nlink_t link_num;
    uid_t user_id;
    gid_t grp_id;
    dev_t device_special_id;
    off_t byte_size;
    blksize_t block_size_sys;
    blkcnt_t block_512_alloc;
    time_t ctime;
    time_t mtime;
    time_t atime;
    char **stat_array_info;
} t_content;

typedef struct s_parsed
{
    char *msg;
    char *error;
    char *success;
    char **array;
    int correct;
} t_parsed;

tt_list *ex_get_dir_list(char *path, long *flag);
void ex_list_del_all(tt_list **head, void (*del)(void *));
void ex_list_del_one(tt_list *element, void (*del)(void *));
tt_list *ex_list_last(tt_list *list);
void ex_list_push_back(tt_list **head, tt_list *new);
void ex_list_push_front(tt_list **head, tt_list *new);
tt_list *ex_listnew(void *content);
void ex_print_error_exit(char *str);
size_t ex_str_array_len(const char **arr);
// tt_list *pivot_point( tt_list *start,  tt_list *end);
char **array_str_stat_info(struct stat *info);
void ex_print_dir_rec(char *path, char *flag);
char *ex_get_file(const char *path);
void quick_sort(tt_list *head, tt_list *last, long *flag);
int set_flag_up(char *str, long *options);
int check_flag_up(char c, long *options);
int sort_by_flag(void *iter, void *end, long *flag);

#endif