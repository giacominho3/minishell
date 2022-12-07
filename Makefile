NAME = Minishell

CC = gcc

CFLAGS = -Wextra -Werror -Wall

LIBFT_PATH = libft/

LIBFT = $(LIBFT_PATH)libft.a

#M1 flags: -L/opt/homebrew/opt/ruby/lib -I/opt/homebrew/opt/ruby/include
#42 flags: -L$$HOME/.brew/opt/readline/lib -I $$HOME/.brew/opt/readline/include
RL_FAGS = -L/usr/include -lreadline -L$$HOME/.brew/opt/readline/lib -I $$HOME/.brew/opt/readline/include

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
			src/signals/signals.c src/parsing/utils/parsing_utils.c \
			src/parsing/quotes_handler/quotes_handler.c src/parsing/tokenizer/tokenization_utils/body_scan.c \
			src/parsing/tokenizer/tokenization_utils/head_scan.c src/parsing/tokenizer/tokenization_utils/scan_utils.c \
			src/parsing/tokenizer/tokenization_utils/tokenization_utils.c src/parsing/tokenizer/token_list2.c \
			src/parsing/tokenizer/token_list.c src/parsing/tokenizer/tokenizer.c src/parsing/tokenizer/tokenization_utils/tail_scan.c \
			src/exec/pipeline.c src/exec/pipe_utils.c src/exec/access/access.c src/exec/access/access_utils.c \
			src/exec/bin/export.c src/exec/bin/export_utils.c src/exec/bin/echo.c src/exec/bin/env.c \

OBJECTS = $(CFILES:.c=.o)

all: libraries $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf $(UP)$(CUT)

libraries:
	@echo $(B)
	make -C $(LIBFT_PATH) all
#	@echo $(B)
#	make -C $(PRINTF_PATH) all

$(NAME): $(OBJECTS)
	@echo $(Y)Compiling [$(CFILES)]...$(X)
	@echo $(G)Finished [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	$(CC) $(CFLAGS) $(LIBFT) $(RL_FAGS) $(OBJECTS) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@make -C $(LIBFT_PATH) clean
#	@make -C $(PRINTF_PATH) clean
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)
	@echo $(R)Removed libraries.o$(X)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
#	@make -C $(PRINTF_PATH) fclean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

norm:
	norminette libft src incl

run: make re && ./Minishell

.PHONY: all clean fclean re norm
