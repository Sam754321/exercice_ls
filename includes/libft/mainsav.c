#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"

#define D_ERROR	{ printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__); return (0); }
#define RANDT	512

int main(int ac, char **av)
{
//  char s[12];
//  char d[15] = {0};
//  int i;


// for (i = 0; i< 10; i++)
// {
// 	s[i] = i;
// 	printf("%d%d\n",s[i], d[i]);
// }
// printf("%p %p\n",ft_memccpy(d,s,4,10), &d[5]);
// for (i = 0; i< 10; i++)
// {
// 	s[i] = i;
// 	printf("%d %d\n",s[i], d[i]);
// }
// printf("%ld  \n", ft_strlen("salut"));
// char *str = "a3sd4AB0@)uilf:/;dDa  09AZaz 18BYby";
// i = 0;
// while(*str++)
// 	printf("%c --->%s\n",*str,  ft_isprint(*str) ? " vrai " : " faux");
// printf("%s\n",str );
// char *str2 = "a3sd4AB0@)uilf:/;dDa   09AZaz 18BYby";

// int x;
// for(x = 0; x < ft_strlen(str2); x++)
// {
	
// 	printf("%c --->%c  %c\n",str2[x], ft_tolower(str2[x]),ft_toupper(str2[x]) ) ;

// }

// char *strb = "-123214  887 4zte";
// char *stra = "-123214 987 zte";
// printf("%d\n",ft_atoi(stra) );

// printf("%d\n", ft_strncmp(stra,strb,50000));
// printf("%d\n", strncmp(stra,strb,50000));
// printf("%d\n", strcmp(s%stra,strb));
// printf("%d\n", ft_strcmp(stra,strb));
// printf(" %s\n",ft_strnstr("azer 4azerty aze4rty", "rty",11 ) );
// printf(" %s\n",ft_strnstr("azer azerty azerty", "\0",11 ) );
// printf(" %s\n",ft_strstr("azer azerty azerty", "") );
// printf(" %s\n",ft_strstr("azer azerty azerty", "ty") );
// printf("%s\n",ft_strrchr(strb, '4') );
// printf("%s\n",ft_strchr(strb, '4') );
// char* cpy = ft_strdup(stra);
// printf("%s  %p  %p %s\n",ft_strdup(stra),stra, ft_strdup(stra),cpy );

// char strc[100] = "abcdefghijklmnopqrstuvwxyz";
// char strd[25] = "aaaaaaaaaa";
// char stre[100] ="a";

// //printf("%s \n",ft_strcpy(strd,strc) );
// //printf("%s\n",ft_strncpy(strd,strc,5) );
// //printf("%s %s\n",strd,ft_strncat(strd,strc,4) );
// printf("%s %ld\n",strc,ft_strlcat(strc,stre,100) );
// char* xx = ft_memalloc(40);

// for(i=0;i<42;i++)
// 	printf("%p\n",&xx[i] );
// char* tt = &xx[39];
// printf("azrfr%s\n",tt );
// ft_memdel((void**)&xx);



// printf("%p\n",xx );
// printf("azrfr%s\n",tt );

// tt = ft_strnew(42);
// printf("%s%ld\n",tt, ft_strlen(tt) );




// char * aA = "aze";
// char *bB = "abcdefghijklmnopqrstuvwxyz";
// printf("%d\n", ft_strequ(aA,bB) );
// printf("%d\n", ft_strnequ(aA,bB,0) );

// printf("%s%ld\n",ft_strjoin(bB,aA),ft_strlen(ft_strjoin(bB,aA)) );

// printf("%s %s\n",ft_strsub(bB,1,100),"a" );
// char *cC = "aa    aa aa aa aa  aa aa aa a";
// printf("!!%s!!\n",ft_strtrim(cC) );
// char *dD = "1  2 " ;
// printf("%s\n",dD );
// // if (ac > 2)
// // {
// // 	char **array1;
// // 	array1 = ft_strsplit(av[1], av[2][0]);
// // 	while (array1 && *array1)
// // 	{
// // 		printf("!%s!\n", *array1);
// // 		array1++;
// // 	}

// // }
// printf("%s!!\n",ft_itoa(-123456789));

// ft_putendl(bB);
// ft_putnbr_fd(1234,1);
// ft_putchar_fd('r',1);
// ft_putstr_fd("azer",1);

// /*" salut " " bonjour " "yo"
// char **array = (char **)malloc(sizeof(char *) * 4);;
// array[0] = ft_strdup("salut");
// array[1] = ft_strdup("bonjour");
// array[2] = ...
// array[3] = NULL;

// while (array[i]) */
// char *a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// char *c = "cabdeadazdazd";
// char b[1000];

// ft_strncpy(b,a,10);
// printf("%s\n",b );

// ft_strrchr(a,'c');
//printf("%d\n",ft_strcmp(a,c) );

 //int i;
// for(i = 0;i<127;i++)
// {	printf("%d\n",isalpha(i) );
// 	printf("%d\n", isprint(i));
// }

 // for(i=-300;i<1000;i++)
 // {
// 	printf("%d %d %u %u\n",ft_tolower(i),tolower(i),ft_tolower(i),tolower(i) );
// 	printf("%d %d %u %u\n",ft_toupper(i),toupper(i),ft_toupper(i),toupper(i) );
	//  printf("%d %c %d\n",ft_isalnum(i),isalnum(i),i);
 // }
//printf("%d %d\n",ft_atoi("12-12"),atoi("12-12") );

// 
// printf("%d %d\n",ft_atoi("\n\v\t\r\f -+123"),atoi("\n\v\t\r\f -+123") );
// printf("%d\n",isspace(' ') );

//     char*a="\n\v\t\r\f -123";
//      int d;
//     for(d=0;d < strlen(a);d++)
// 	    printf("%d\n",ft_isspace(a[d]) );
// 	printf("%d %d\n",ft_atoi("+123"),atoi("+123") );
// size_t		i, j;
// 	char		str[12] = {0};

// 	if (atoi("\n\v\t\r\f -123") != ft_atoi("\n\v\t\r\f -123"))
// 		printf("%d---1>%d \n",atoi("\n\v\t\r\f -123") , ft_atoi("\n\v\t\r\f -123"));
// 	if (atoi("12-3") != ft_atoi("12-3"))
// 		printf("%d---2>%d \n",atoi("12-3") , ft_atoi("12-3"));
// 	if (atoi("-+123") != ft_atoi("-+123"))
// 		printf("%d---3>%d \n",atoi("-+123") , ft_atoi("-+123"));
// 	if (atoi("a123") != ft_atoi("a123"))
// 		printf("%d---4>%d \n",atoi("a123") , ft_atoi("a123"));
// 	if (atoi("123a") != ft_atoi("123a"))
// 		printf("%d---5>%d \n",atoi("123a") , ft_atoi("123a"));
// 	if (atoi("123") != ft_atoi("123"))
// 		printf("%d---6>%d \n",atoi("123") , ft_atoi("123"));
// 	if (atoi("-123") != ft_atoi("-123"))
// 		printf("%d---7>%d \n",atoi("-123") , ft_atoi("-123"));
// 	if (atoi("+123") != ft_atoi("+123"))
// 		printf("%d---8>%d \n",atoi("+123") , ft_atoi("+123"));
// 	if (atoi(" - 123") != ft_atoi(" - 123"))
// 		printf("%d---9>%d \n",atoi(" - 123") , ft_atoi(" - 123"));
// 	if (atoi("\t -123") != ft_atoi("\t -123"))
// 		printf("%d---10>%d \n",atoi("\t -123") , ft_atoi("\t -123"));
// 	if (atoi("-2147483648") != ft_atoi("-2147483648"))
// 		printf("%d---11>%d \n",atoi("-2147483648") , ft_atoi("-2147483648"));
// 	if (atoi("2147483647") != ft_atoi("2147483647"))
// 		printf("%d---12>%d \n",atoi("2147483647") ,ft_atoi("2147483647"));
// 	if (atoi("") != ft_atoi(""))
// 		printf("%d---13>%d \n",atoi("") , ft_atoi(""));
// 	i = 0;
// 	while (i < RANDT)
// 	{
// 		j = 0;
// 		while (j < 10)
// 		{
// 			str[j] = ((char)(rand() % 10) + '0');
// 			j++;
// 		}
// 		str[11] = 0;
// 		if (atoi(str) != ft_atoi(str))
// 			printf("%d--->%d \n",atoi(str) ,ft_atoi(str));
// 		i++;
// 	}

//printf("%d\n",ft_strequ("","") );
// printf("%s\n",ft_itoa(-2147483648)) ;
// //printf("%s\n",ft_strsplit("*********", '*')[0] );
// printf("!%s!\n",ft_strtrim("           \t \t          ") );  

// char *test;
// test = "testlst";

// printf("!!%s!!\n",(ft_lstnew(test,ft_strlen(test))->content )  );


/*static void	test_lstiter(void)
{
	int		test[1], ctrl[1];
	t_list	*lst;

	print_test_name("lstiter");
	init(ctrl, 1, 0);
	init(test, 1, 1);
#ifdef SEGFAULT_ME
	//ft_lstiter(NULL, &ft_liter);
	lst = ft_lstnew("test string", sizeof(char) * 12);
	ft_lstiter(lst, NULL);
	free(lst->content);
	free(lst);
	ft_lstiter(NULL, NULL);
#endif
	lst = NULL;
	ft_lstadd(&lst, ft_lstnew("test3", 5));
	ft_lstadd(&lst, ft_lstnew("test2", 5));
	ft_lstadd(&lst, ft_lstnew("test1", 5));
	ft_lstiter(lst, &f_liter);
	ft_lstiter(lst, &f_liter);
	if (!cmp((char *)lst->content, "vguv3")
		&& !cmp((char *)lst->next->content, "vguv4")
		&& !cmp((char *)lst->next->next->content, "vguv5"))
		test[0] = 0;
	print_test_results(test, ctrl, 1, NULL);
}

static void	test_lstmap(void)
{
	int		test[3], ctrl[3];
	t_list	*lst1, *lst2;

	print_test_name("lstmap");
	init(ctrl, 3, 0);
	init(test, 3, 1);
#ifdef SEGFAULT_ME
	//ft_lstmap(NULL, &ft_lmap);
	lst1 = ft_lstnew("test string", sizeof(char) * 12);
	ft_lstmap(lst1, NULL);
	free(lst1->content);
	free(lst1);
	ft_lstmap(NULL, NULL);
#endif
	lst1 = NULL;
	ft_lstadd(&lst1, ft_lstnew("test3", 5));
	ft_lstadd(&lst1, ft_lstnew("test2", 5));
	ft_lstadd(&lst1, ft_lstnew("test1", 5));
	lst2 = ft_lstmap(lst1, &f_lmap);
	if (!cmp((char *)lst2->content, "uftu2")
		&& !cmp((char *)lst2->next->content, "uftu3")
		&& !cmp((char *)lst2->next->next->content, "uftu4"))
		test[0] = 0;
	if (lst2->content_size == 5
		&& lst2->next->content_size == 5
		&& lst2->next->next->content_size == 5)
		test[1] = 0;
	if (!lst2->next->next->next)
		test[2] = 0;
	print_test_results(test, ctrl, 3, NULL);
}

static void	test_lstnew(void)
{
	int		test[11], ctrl[11], warning[]={8, -1};
	char	str[]="test string";
	t_list	*lst;

	print_test_name("lstnew");
	init(ctrl, 11, 0);
	init(test, 11, 1);
	lst = ft_lstnew(str, sizeof(*str) * (strlen(str) + 1));
	if (lst)
	{
		test[0] = cmp(str, lst->content);
		if (str != lst->content)
			test[1] = 0;
		if (lst->content_size == sizeof(*str) * (strlen(str) + 1))
			test[2] = 0;
		if (!lst->next)
			test[3] = 0;
		free(lst->content);
		free(lst);
	}
	lst = ft_lstnew(NULL, 10);
	if (lst)
	{
		if (!lst->content)
			test[4] = 0;
		if (lst->content_size == 0)
			test[5] = 0;
		if (!lst->next)
			test[6] = 0;
		free(lst->content);
		free(lst);
	}
	lst = ft_lstnew(str, SIZE_MAX);
	if (!lst)
		test[7] = 0;
	else
	{
		free(lst->content);
		free(lst);
	}
	lst = ft_lstnew(str, 0);
	if (lst)
	{
		if (!lst->content)
			test[8] = 0;
		if (lst->content_size == 0)
			test[9] = 0;
		if (!lst->next)
			test[10] = 0;
		free(lst->content);
		free(lst);
	}
	print_test_results(test, ctrl, 11, warning);
}



                    
} 