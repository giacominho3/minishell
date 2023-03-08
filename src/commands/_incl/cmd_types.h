#ifndef MINISHELL_CMD_TYPES_H
# define MINISHELL_CMD_TYPES_H

struct	s_main;

typedef struct s_cmd
{
	char			*cmd;
	char			**execve_args;
	t_token_list	*tok_head;
	struct s_main	*main_ref;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

#endif
