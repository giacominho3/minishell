#ifndef MINISHELL_MAIN_TYPES_H
# define MINISHELL_MAIN_TYPES_H

typedef struct s_main
{
	char 	*cmd_line;
	t_env	*env_head;
	t_cmd	*cmd_head;
	int		pid;
	int		exit_status;
}	t_main;

#endif
