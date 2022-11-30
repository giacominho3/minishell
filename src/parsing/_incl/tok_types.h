#ifndef MINISHELL_TOK_TYPES_H
#define MINISHELL_TOK_TYPES_H

typedef enum e_tokens
{
	TOK_CMD,
	TOK_FLAGS,
	TOK_HEREDOC,
	TOK_REDIRECTION,
	TOK_ARGS,
	TOK_PREV_LOGIC_OP,
	TOK_NEXT_LOGIC_OP,
	TOK_IN_FILE,
	TOK_OUT_FILE,
	TOK_ERROR,
}	t_tokens;

typedef struct s_token_list
{
	t_tokens			type;
	char				*token;
	struct s_token_list	*next;
	struct s_token_list	*prev;
}	t_token_list;

#endif //MINISHELL_TOK_TYPES_H
