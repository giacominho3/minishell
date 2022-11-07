#ifndef MINISHELL_TOKENS_H
# define MINISHELL_TOKENS_H
# include "../../../../incl/minishell.h"

typedef enum e_tokens
{
	TOK_CMD,
	TOK_FLAGS,
	TOK_ARGS,
	TOK_PREV_LOGIC_OP,
	TOK_NEXT_LOGIC_OP,
	TOK_IN_FILE,
	TOK_OUT_FILE,
	TOK_ERROR,
}	t_tokens;

typedef struct s_token_list
{
	t_tokens		type;
	char				*token;
	struct s_token_list	*next;
	struct s_token_list	*prev;
}	t_token_list;




#endif //MINISHELL_TOKENS_H

/**
* 		x_1 x_2 x_3 x_4 ...
*/