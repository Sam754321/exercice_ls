#	Program output
NAME = a.out

#	GCC flags -Wall -Wextra $(CFLAGS) -g 
#-fsanitize=address -g
#CFLAGS = -Wall -Wextra -Werror -Weverything -fsanitize=address -g
#CFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -Wall -Wextra -Werror
ALL_CFLAGS = $(CFLAGS)

#	Library files
LIBFLAGS = -lmy -L./includes/libft/includes


#	Ojects/Sources directories
INC_TEST = includes/
SRC_TEST = $(shell find src | grep "\.c$$" | sed "s/\.c$$//g")
INCLUDES += $(addprefix -iquote , $(INC_TEST))
SRCS += $(addsuffix .c, $(SRC_TEST))

#	Extern includes
INC_LIB = include/libft/includes
INCLUDES += $(addprefix -iquote , $(INC_LIB))

#	Final OBJS
OBJS = $(SRCS:.c=.o)

#	Layout
VERBOSE = true

all: header $(NAME) footer

header:
	@echo "\033[33m[\033[4m$(NAME)\033[0m\033[33m] Compile\033[0m"

footer:
	@echo "\033[33m[\033[4m$(NAME)\033[0m\033[33m] Finished\033[0m"

$(NAME): $(OBJS)
ifeq ($(VERBOSE),true)
	@echo "\033[34m. Compile Final .\033[0m $(NAME)"
else
	@printf"\033[34m.\033[0m\n"
endif
	@$(CC) $(ALL_CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) -L includes/libft/includes includes/libft/libft.a

%.o: %.c 
ifeq ($(VERBOSE),true)
	@echo "\033[34m. Compile .\033[0m $<"
else
	@printf"\033[34m.\033[0m"
endif
	@$(CC) $(ALL_CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo -e "\033[33m[\033[4m$(NAME)\033[0m\033[33m] >>\033[0m \033[31mCLEAN all object files (*.o)\033[0m"
	@$(RM) $(OBJS)

fclean: clean
	@echo -e "\033[33m[\033[4m$(NAME)\033[0m\033[33m] >>\033[0m \033[31mFCLEAN project binary ($(NAME))\033[0m"
	@$(RM) $(NAME)

re: fclean all
