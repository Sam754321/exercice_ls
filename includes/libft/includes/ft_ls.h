#ifndef FT_LS
#define FT_LS

#include <stdio.h>
#include <stddef.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <wchar.h>
#include <pwd.h>
#include <grp.h>
#include "libft.h"

#define FLAG_l 1
#define FLAG_r 2
#define FLAG_a 4
#define FLAG_R 8
#define FLAG_t 32
#define FLAG_A 64
#define FLAG_C 128
#define FLAG_x 256
#define FLAG_d 512
#define FLAG_L 1024
#define FLAG_H 2048
#define FLAG_F 4096
#define FLAG_p 8192
#define FLAG_i 16384
#define FLAG_n 32768
#define FLAG_s 65536
#define FLAG_h 131072
#define FLAG_S 262144
#define FLAG_X 524288
#define FLAG_v 1048576
#define FLAG_c 2097152
#define FLAG_u 4194304
#define FLAG_1 8388608
#define FLAG_STOP 16777216
#define FLAG_CHECKPATH 33554432
#define FLAG_ORPHAN 67108864

#define LSERR_1 "Usage: ls [-1AaCxdLHRFplinshrSXvctu] [-w WIDTH] [FILE]...\nList directory contents\n-1      One column output\n-a      Include entries which start with .\n-A      Like -a, but exclude . and ..\n-x      List by lines\n-d      List directory entries instead of contents\n-L      Follow symlinks\n-H      Follow symlinks on command line\n-R      Recurse\n-p      Append / to dir entries\n-F      Append indicator (one of */=@|) to entries\n-l      Long listing format\n-i      List inode numbers\n-n      List numeric UIDs and GIDs instead of names\n-s      List allocated blocks\n-lc     List ctime\n-lu     List atime\n--full-time     List full date and time\n-h      Human readable sizes (1K 243M 2G)\n--group-directories-first\n-S      Sort by size\n-X      Sort by extension\n-v      Sort by version\n-t      Sort by mtime\n-tc     Sort by ctime\n-tu     Sort by atime\n-r      Reverse sort order"
#define ORPHAN_BREAK "----------"

typedef struct s_dispinfolst
{
	char* nblienstr;
	int nblienlen;
	int nblienlenmax;
	char* uidstr;
	int uidlen;
	int uidlenmax;
	char* grpidstr;
	int grpidlen;
	int grpidlenmax;
	char* taillestr;
	int taillelen;
	int taillelenmax;
}				t_dispinfolst;

typedef struct s_lslst
{
	char *nam;
	char *path;
	char *nam_link;
	char *infolst_link;
	char *infolst;
	size_t sizlst;
	size_t lennamax;
	size_t lennam;
	int hidenfil;
	int i;
	int flag;
	size_t col;
	size_t numcol;
	size_t ligne;
	mode_t stmodestat;
	struct timespec sttimestat;
	long totalblok;
	char staterror;
	char* liensymb;
	char* droitsymb;
	t_dispinfolst *displayinfo; 
	struct s_lslst *next;
} t_lslst;

int ft_ls(int av,const char **ac);
int parse_path(int flag,char **tab_path);
char *ft_strdup_exit(const char *s);
int parse_flag_path(int ac,const char **av,char ***tab_path);
int checkflag(char *s,int flag);
char **checkpath(char* av);
void * ft_memalloc_exit(size_t size);
int dirverif(char *s);
t_lslst **ls(char *chemi, int flag);
char *fils(char *chemin, char *fil);
char *checkdroit(struct stat *info);
size_t lstsiz(t_lslst *lst);
t_lslst **maloctab(t_lslst *lst);
void spaceafich(t_lslst *lst);
int checkcompressed(char *nam);
int checkaudio(char *nam);
int checkimg(char *nam);
int trimtime(void *a, void *b);
int trinam(void *a, void *b);
t_dispinfolst *parseinfolst(struct stat *info);
char *subordup(char *str, int n);
void affichlst_TEST(t_lslst *lst);
void putnspace(char *str, int nspace,int len, int beforeafter);
void affichnam(char *nam,char *infolst,int staterror);
void affich_flag_l(t_lslst *tmplst, char *tmpath);
void parse_link(t_lslst *tmplst,char *tmpath);

#endif