#ifndef MINISHELL_ENV_TYPES_H
#define MINISHELL_ENV_TYPES_H

typedef struct	s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

#endif