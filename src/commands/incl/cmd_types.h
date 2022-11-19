#ifndef MINISHELL_CMD_TYPES_H
#define MINISHELL_CMD_TYPES_H

typedef struct	s_cmd
{
	t_token_list	*tok_head;
	char				*cmd;
	struct s_cmd		*next;
	struct s_cmd		*prev;
} t_cmd;

#endif
