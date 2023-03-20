NAME=minishell

CC=gcc

LIBFT=./libft/libft.a

FLAGS=-Wall -Werror -Wextra

READLINE = -L$$HOME/.brew/opt/readline/lib -I$$HOME/.brew/opt/readline/include
#M1 flags: -L/opt/homebrew/opt/readline/lib -I/opt/homebrew/opt/readline/include
#42 flags: L$$HOME/.brew/opt/readline/lib -I$$HOME/.brew/opt/readline/include

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
P = "\033[36m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

SRCS=	src/main.c src/parsing/parsing.c src/parsing/utils/parsing_len_utils.c \
			src/syntax/syntax.c src/syntax/utils/syntax_utils.c src/syntax/utils/syntax_utils2.c \
			src/utils/string_utils.c src/utils/string_utils2.c src/utils/utils.c \
			src/env/env_lists.c src/env/env.c src/env/search_env.c src/utils/string_utils3.c \
			src/commands/commands.c src/commands/cmds_utils.c src/commands/cmds_lists.c \
			src/signals/signals.c src/parsing/utils/parsing_utils.c \
			src/parsing/quotes_handler/quotes_handler.c src/parsing/tokenizer/tokenization_utils/body_scan.c \
			src/parsing/tokenizer/tokenization_utils/head_scan.c src/parsing/tokenizer/tokenization_utils/scan_utils.c \
			src/parsing/tokenizer/tokenization_utils/tokenization_utils.c src/parsing/tokenizer/token_list2.c \
			src/parsing/tokenizer/token_list.c src/parsing/tokenizer/tokenizer.c src/parsing/tokenizer/tokenization_utils/tail_scan.c \
			src/exec/pipeline.c src/exec/pipe_utils.c src/exec/access/access.c src/exec/access/access_utils.c \
			src/exec/bin/export.c src/exec/bin/export_utils.c src/exec/bin/echo.c src/exec/bin/env.c src/exec/bin/pwd.c src/exec/bin/cd.c src/exec/bin/unset.c \
			src/exec/bin/exit.c src/exec/redirections/redirections.c src/exec/heredoc/heredoc.c src/gc/gc_list.c src/exec/bin/export_utils2.c \

OBJS=$(SRCS:.c=.o)

%.o:%.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(FLAGS) -c $< -o$@
	@printf $(UP)$(CUT)
#-L/opt/homebrew/opt/readline/lib -I/opt/homebrew/opt/readline/include
#L/usr/include -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600

#may need this flag on asahi  -Wl,--allow-multiple-definition
$(NAME): $(OBJS) $(LIBFT)
	@echo $(Y)Compiling [$(SRCS)]...$(X)
	@echo $(G)Finished [$(SRCS)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	$(CC) $(FLAGS) $(READLINE) $(SRCS) $(LIBFT) -o $(NAME) -lreadline
	@echo $(G)Finished [$(NAME)]$(X)

$(LIBFT):
	@echo $(B)
	$(MAKE) -C ./libft/

all:$(NAME)

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C ./libft
	@echo $(R)Removed [$(OBJS)]$(X)
	@echo $(R)Removed libraries.o$(X)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

.PHONY: all clean fclean re
