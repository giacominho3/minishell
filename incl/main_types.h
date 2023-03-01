#ifndef MINISHELL_MAIN_TYPES_H
# define MINISHELL_MAIN_TYPES_H

int	g_exit_status;

typedef struct s_main
{
	char		*cmd_line;
	t_env		*env_head;
	t_cmd		*cmd_head;
	t_export	*export_head;
}	t_main;

#endif
