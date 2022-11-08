NAME = Minishell

CC = gcc

CFLAGS = -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include/readline -lreadline -Wextra -Werror -Wall

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
P = "\033[36m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = src/main.c src/parsing/parsing.c src/parsing/utils/parsing_len_utils.c \
			src/syntax/syntax.c src/syntax/utils/syntax_utils.c \
			src/utils/string_utils.c src/utils/string_utils2.c src/utils/utils.c \
			src/env/env_lists.c src/env/env.c src/env/search_env.c src/utils/string_utils3.c \
			src/commands/commands.c src/commands/cmds_utils.c src/commands/cmds_lists.c \
			src/signals/signals.c \

OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(UP)$(CUT)

libraries:
#	@echo $(B)
#	make -C $(LIBFT_PATH) all
#	@echo $(B)
#	make -C $(PRINTF_PATH) all

#$(OBJECTS)
$(NAME): $(OBJECTS)
	@echo $(Y)Compiling [$(CFILES)]...$(X)
	@echo $(G)Finished [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
#	@make -C $(LIBFT_PATH) clean
#	@make -C $(PRINTF_PATH) clean
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)
	@echo $(R)Removed libraries.o$(X)

fclean: clean
#	@make -C $(LIBFT_PATH) fclean
#	@make -C $(PRINTF_PATH) fclean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

norm:
	norminette ft_printf utils checker

#run:	all

.PHONY: all clean fclean re norm