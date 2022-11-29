#ifndef MINISHELL_CMD_TYPES_H
#define MINISHELL_CMD_TYPES_H

struct s_main;

typedef struct	s_cmd
{
	struct s_main	*main_ref;
	t_token_list	*tok_head;
	char			*cmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
	char			*out;
}	t_cmd;

#endif
