#include "../../includes/libft/includes/libft.h"
#include "../../includes/ls_inc.h"

#define CURRENT_DIR "."
#define ERROR_MALLOC "Malloc() call failed, exit"
#define ERROR_OPT_1 "Option invalid or not supported, exit"
#define ERROR_OPT_2 "ls: error on -- no options available, exit"
#define EXIT_MALLOC 1
#define EXIT_OPTION_1 2
#define EXIT_OPTION_2 3
#define ASSIGN_BIT(x) ((1L << x))
#define VALUE_ALPHA_BIT(x) ((x < 97) ? x - 65 + 26 : x - 97)
#define ALLOWED_OPTIONS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMONPQRSTUVWXYZ"
#define SORT_OPTIONS "StUvX"
#define EXCLUSIV_OPT_1 "uc"

typedef struct s_env
{
    long options;

} t_env;

/*
    classic strlen
*/
static size_t s_len(char *str)
{
    size_t ret;

    ret = 0;
    if (!str)
        return ret;
    while (str[ret])
        ret++;
    return ret;
}

/*
    print msg on STDERR
    Exit with error code if should_exit > 0
*/
static void print_error_exit(char *msg, int error, char should_exit)
{
    write(2, msg, s_len(msg));
    if (should_exit)
        exit(error);
}

/*
    classic strdup
*/
static char *t_dup(char *str)
{
    char *dup;
    size_t len;

    if (!str)
    {
        print_error_exit("Dup failed", 0, 0);
        return NULL;
    }
    len = s_len(str);
    dup = malloc(sizeof(char) * len + 1);
    if (!dup)
        print_error_exit(ERROR_MALLOC, EXIT_MALLOC, 1);
    dup[len] = 0;
    len = 0;
    while (str[len])
    {
        dup[len] = str[len];
        len++;
    }
    return dup;
}

/*
    delete array
*/
static void t_del_arr(char ***addr_arr)
{
    int i;
    char **arr;

    i = 0;
    if (!addr_arr)
        return;
    arr = *addr_arr;
    while (arr && arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
    *addr_arr = NULL;
}

/*
    classic is_alpha
*/
static int c_is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

/*
    Singleton with env variable
    if called with a valid env will update static variable
    always return static variable
*/
t_env *get_set_env(t_env *new_env)
{
    static t_env *env = NULL;

    if (new_env)
        env = new_env;
    return env;
}

/*
    check if env is allocated
    init every variables in env
    set env in singleton
*/
static void init_env(t_env *env)
{
    if (!env)
        print_error_exit(ERROR_MALLOC, EXIT_MALLOC, 1);
    env->options = 0;
    get_set_env(env);
}

/*
    static fonction for norm
    dup a string into an array and increment an int
*/
static void dup_inc(char **to_ret, char *to_dup, int *j)
{
    to_ret[*j] = t_dup(to_dup);
    (*j)++;
}

/*
    check if the options is supported
*/
static int is_valid(char *str, char c)
{
    int i;

    i = 0;
    if (!str || !c_is_alpha(c))
        return 0;
    while (str[i])
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

/*
    return 1 if c is set
    return 0 if not
*/
static int is_opt_set(long options, char c)
{
    return options & ASSIGN_BIT(VALUE_ALPHA_BIT(c)) ? 1 : 0;
}

/*
    remove all options send
    set o as clean new option
*/
static void remove_set_exclusiv_options(t_env *env, char *options, char o)
{
    size_t j;

    for (j = 0; j < s_len(options); j++)
    {
        if (is_opt_set(env->options, options[j]))
            env->options -= ASSIGN_BIT(VALUE_ALPHA_BIT(options[j]));
    }
    env->options |= ASSIGN_BIT(VALUE_ALPHA_BIT(o));
}

/*
    exception on 'f' flag
    remove options l and s
    add options a and u
*/
static void remove_set_f(t_env *env)
{
    if (is_opt_set(env->options, 'l'))
        env->options -= ASSIGN_BIT(VALUE_ALPHA_BIT('l'));
    if (is_opt_set(env->options, 's'))
        env->options -= ASSIGN_BIT(VALUE_ALPHA_BIT('s'));
    env->options |= ASSIGN_BIT(VALUE_ALPHA_BIT('a'));
    env->options |= ASSIGN_BIT(VALUE_ALPHA_BIT('U'));
}

/****
    set options with priority
    u and c are not compatible
    for every sort last one is the one used
    u and c are valid only if last sort option is t //implementation todo in sort

    categories sort :
    f : disable -l -s enable -a -U (if f r has no effect)
    r : reverse sort order (no effect on f/U)
    S : sort on Size
    t : sort on time
    U : no sort (r no effect)
    v : sort on version
    X : sort alpha on extensions

*/
static void set_options(char *av, int i)
{
    t_env *env;

    env = get_set_env(NULL);
    while (av && av[i])
    {
        if (!is_valid(ALLOWED_OPTIONS, av[i]))
            print_error_exit(ERROR_OPT_1, EXIT_OPTION_2, 1);
        if (is_valid(SORT_OPTIONS, av[i]))
            remove_set_exclusiv_options(env, SORT_OPTIONS, av[i]);
        else if (is_valid(EXCLUSIV_OPT_1, av[i]))
            remove_set_exclusiv_options(env, EXCLUSIV_OPT_1, av[i]);
        else if (av[i] == 'f')
            remove_set_f(env);
        else
            env->options |= ASSIGN_BIT(VALUE_ALPHA_BIT(av[i]));
        i++;
    }
}

/*
    loop on all arg, to check options and cp args into var to_ret
*/
static int loop_on_args(char **av, char **to_ret, char flag_stop_args, int i)
{
    int j;
    size_t len;

    j = 0;
    len = 0;
    while (av[i])
    {
        if (flag_stop_args || av[i][0] != '-')
            dup_inc(to_ret, av[i], &j);
        else
        {
            len = s_len(av[i]);
            if (len == 1)
                dup_inc(to_ret, av[i], &j);
            else
            {
                if (av[i][1] == '-' && len > 2)
                    print_error_exit(ERROR_OPT_2, EXIT_OPTION_1, 1);
                else if (av[i][1] == '-')
                    flag_stop_args = 1;
                else
                    set_options(av[i], 1);
            }
        }
        i++;
    }
    return j;
}

/*
    base of checking for arg
    check for error, malloc and dup array of valid args
*/
static char **check_options(char **av, int len)
{
    char **ret;
    char **full_cp;
    int tab_len;

    full_cp = malloc(sizeof(char *) * len + 1);
    ret = NULL;
    if (!full_cp)
        print_error_exit(ERROR_MALLOC, EXIT_MALLOC, 1);
    while (len)
    {
        full_cp[len] = 0;
        len--;
    }
    tab_len = loop_on_args(av, full_cp, 0, 0);
    if (tab_len)
    {
        ret = malloc(sizeof(char *) * tab_len + 1);
        if (!ret)
            print_error_exit(ERROR_MALLOC, EXIT_MALLOC, 1);
        tab_len = 0;
        while (full_cp[tab_len])
        {
            ret[tab_len] = t_dup(full_cp[tab_len]);
            tab_len++;
        }
    }
    t_del_arr(&full_cp);
    return ret;
}

/*
------------------------------------------------------------------------------------------------------
                                    DEBUG FONCTIONS
------------------------------------------------------------------------------------------------------
*/

/*
classic print array of char*
*/
static void t_print_array(char **array)
{
    int i;

    i = 0;
    if (!array)
        return;
    while (array && array[i])
    {
        printf("%s\n", array[i]);
        i++;
    }
}

/*
    print current options sets
*/
static void t_print_options(long options)
{
    int i;
    char *tmp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMONPQRSTUVWXYZ";

    printf("options : ");
    i = 0;
    while (tmp[i])
    {
        if (is_opt_set(options, tmp[i]))
            printf(" -%c ", tmp[i]);
        i++;
    }
    printf("\n");
}

/*
    print long in binary
    01
*/
static void t_print_binary(long options)
{
    size_t i;
    size_t s;

    i = 0;
    s = sizeof(options) * 8;
    while (i < s)
    {
        if (options & (1L << i))
            printf("1");
        else
            printf("0");
        i++;
    }
}

/*
    main
    malloc env
    init env
    check args
    algo
    debug
    destructor
*/
int main(int ac, char **av)
{
    char **real_av;
    t_env *env;
    int i;

    i = 0;
    env = malloc(sizeof(t_env));
    init_env(env);
    if (ac > 1)
        real_av = check_options(&av[1], ac - 1);
    if (real_av)
    {
        // no arg, current directory
        while (real_av[i])
        {
            ex_print_dir_rec(real_av[i], env->options);
            i++;
        }
    }
    else
    {
        // real_av not sorted
    }
    // debug
    t_print_array(real_av);
    t_print_options(env->options);
    t_print_binary(env->options);
    // end debug
    env ? free(env) : 0;
    real_av ? t_del_arr(&real_av) : 0;
}