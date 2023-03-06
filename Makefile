NAME=minishell

CC=gcc

FLAGS=-Wall -Werror -Wextra

SRCS=	src/main.c src/parsing/parsing.c src/parsing/utils/parsing_len_utils.c \
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
			src/exec/bin/export.c src/exec/bin/export_utils.c src/exec/bin/echo.c src/exec/bin/env.c src/exec/bin/pwd.c src/exec/bin/cd.c src/exec/bin/unset.c \
			src/exec/bin/exit.c src/exec/redirections/redirections.c src/exec/heredoc/heredoc.c src/gc/gc_list.c\

OBJS=$(SRCS:.c=.o)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o$@

LIBFT=./libft/libft.a
READLINE = -L/usr/include -lreadline -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -Wl,--allow-multiple-definition $(FLAGS) $(SRCS) $(LIBFT) -o $(NAME) $(READLINE)
$(LIBFT):
	$(MAKE) -C ./libft/
all:$(NAME)

clean:
	rm -f *.o
	$(MAKE) clean -C ./libft
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft
re: fclean all

.PHONY: all clean fclean re
