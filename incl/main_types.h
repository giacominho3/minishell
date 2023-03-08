#ifndef MINISHELL_MAIN_TYPES_H
# define MINISHELL_MAIN_TYPES_H

typedef struct s_main
{
	char		*cmd_line;
	char		**env_mat;
	t_env		*env_head;
	t_cmd		*cmd_head;
	t_export	*export_head;
	int			exit_status;
}	t_main;

#endif
