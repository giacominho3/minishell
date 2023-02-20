#ifndef MINISHELL_BUILTINS_H
# define MINISHELL_BUILTINS_H
# include "../../../incl/minishell.h"

/**
 * export
 */
int		export_printing(t_cmd *cmd);
void	copy_env_to_export(t_export **head, char **envp);
void	add_env_and_export(t_export *export, t_env *env);
int		builtin_export(t_cmd *cmd);
int		add_export_element(t_cmd *cmd);
void	print_export(t_cmd *cmd);
void	add_elements_to_export(t_cmd *cmd);


/**
 * pwd
 */
int		builtin_pwd(t_cmd *cmd);

/**
 * cd
 */
int		builtin_cd(t_cmd *cmd);

/**
 * echo
 */
int		builtin_echo(t_cmd *cmd);
/**
 * env
 */
int		builtin_env(t_cmd *cmd);
/**
 * unset
 */
void	unset(t_cmd *cmd);
/**
 * exit
 */
void	builtin_exit(t_cmd *cmd);
#endif
