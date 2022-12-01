#include "../../includes/ls_inc.h"
#include "../../includes/libft/includes/libft.h"

static void sort_list(tt_list *head, long *flag)
{
        if(!head)
                return;
        tt_list *end_lst;
        end_lst = head;
        while(end_lst->next)
                end_lst = end_lst->next;
        quick_sort(head, end_lst, flag);
}

static void check_err(int nb, char *str)
{
    if(nb != 0)
    {
                ft_putnbr(errno);
                ft_putchar(':');
                perror(str);
    }       
    return;
}

static char *malostr(const char *s1, const char *s2)
{
    char * retstr;

    retstr =NULL;
    if(s1 && s2)
      {
          if(!(retstr = (char *)malloc(sizeof(char) * (ft_strlen((char*)s1) + ft_strlen((char*)s2) + 2))))
                return NULL;
      }
      else if(s1 && !s2)
      {
          if(!(retstr = (char *)malloc(sizeof(char) * (ft_strlen((char*)s1) + 2))))
                return NULL;
      }
      else if(!s1 && s2)
      {
          if(!(retstr = (char *)malloc(sizeof(char) * (ft_strlen((char*)s2) + 1))))
                return NULL;
      }
      return retstr;
}

static char *join_path(const char *s1, const char *s2)
{
  char * retstr;
  int j;
  int i;

  retstr = NULL;
  i = 0;
  j = 0;
  if(s1 || s2)
  { 
      retstr = malostr(s1, s2);
      if(s1)
      {
            for(i = 0; s1[i] != 0; i++)
                retstr[i] = s1[i];
            if(i > 0 && retstr[i - 1] != '/')
	    {
                retstr[i] = '/';
	        i++;
            }
      }
      if(s2)
      {
             for(j = 0; s2[j] != 0; j++, i++)
                retstr[i] = s2[j];
      }
      retstr[i] = 0;
  }
    return retstr;
}

static unsigned char typ_file_stat(struct stat *stat)
{
    if(!stat)
        return 0;
    if(stat->st_mode & S_IFCHR)
            return 'c';
    else if(stat->st_mode & S_IFDIR)
            return 'd';
    else if(stat->st_mode & S_IFIFO)
            return 'f';
    else if(stat->st_mode & S_IFLNK)
            return 'l';
    else if(stat->st_mode & S_IFREG)
            return 'r';
    else if(stat->st_mode & S_IFSOCK)
            return 's';
    else if(stat->st_mode & S_IFBLK)
            return 'b';
    else
            return 'u';
}

static t_content *ex_list_content_new(struct stat *info,char *nam)
{
    t_content *retlist;

    retlist = NULL;
    if(nam)
    {
            if(!(retlist = (t_content*)malloc(sizeof(t_content))))
                    return NULL;
            retlist->path = ft_strdup(nam);
            retlist->len = info->st_size;
            retlist->type = typ_file_stat(info);
            retlist->device_id = info->st_dev;
            retlist->node_num = info->st_ino;
            retlist->file_type = info->st_mode;
            retlist->link_num = info->st_nlink;
            retlist->user_id = info->st_uid;
            retlist->grp_id = info->st_gid;
            retlist->device_special_id = info->st_rdev;
            retlist->byte_size = info->st_size;
            retlist->block_size_sys = info->st_blksize;
            retlist->block_512_alloc = info->st_blocks;
            retlist->ctime = mktime(gmtime(&info->st_ctim.tv_sec));
            retlist->mtime = mktime(gmtime(&info->st_mtim.tv_sec));
            retlist->atime = mktime(gmtime(&info->st_atim.tv_sec));
            retlist->stat_array_info = array_str_stat_info(info);
    }
    return retlist;
}

static tt_list *dir_list_contentt_list(char *path, struct dirent *dir)
{
    struct stat stat_file;
    tt_list *new_lst;
    t_content *new_content;
    char *content_path;

    if(path && dir)
    {
            content_path = join_path(path, dir->d_name);
            if((lstat(content_path, &stat_file) != 0))
            {
                    perror("");
                    printf("lstat_error\n");
            }
            new_content = ex_list_content_new(&stat_file,content_path);
            new_lst = (tt_list*)ex_listnew(new_content);
            free(content_path);
    }
    return new_lst;
}
static void new_or_push_headlst(tt_list **head,char *name_path, struct dirent *tab_dirent)
{
        if(!(*head) && tab_dirent)
                *head = dir_list_contentt_list(name_path, tab_dirent);
        else if(*head && tab_dirent)
                ex_list_push_back(head, dir_list_contentt_list(name_path, tab_dirent));
}
  
tt_list *ex_get_dir_list(char *path, long *flag)
        {
        DIR *dir_opn;
        tt_list *lst_directory;
        struct dirent *tab_dir_info;
        tt_list **head_lst;
        
        lst_directory = NULL;
        head_lst = &lst_directory;
        dir_opn = NULL;
        if(path)
        {
                errno = 0;
                dir_opn = opendir(path);
                //check_err(errno,"opendir");
                if(errno == 13 || errno == 20 || errno == 2)
                {
                        //perror(path);
                        return *head_lst;
                }
                do{
                        errno = 0;
                        tab_dir_info = readdir(dir_opn);
                        check_err(errno,"readdir");
                        if(tab_dir_info)
                                new_or_push_headlst(head_lst, path, tab_dir_info);         
                }    while(tab_dir_info);
                sort_list(*head_lst, flag);
                check_err(errno, "readdir");
                closedir(dir_opn);
                check_err(errno, "closedir");
        }
        return *head_lst;
}