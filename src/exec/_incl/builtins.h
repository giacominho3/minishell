#ifndef MINISHELL_BUILTINS_H
# define MINISHELL_BUILTINS_H
# include "../../../incl/minishell.h"

/**
 * export
 */
void	add_env_and_export(t_export *export, t_env *env);
int		builtin_export(t_cmd *cmd);
int		builtin_pwd(t_cmd *cmd);

/**
 * echo
 */
int		builtin_echo(t_cmd *cmd);
/**
 * env
 */
int	builtin_env(t_cmd *cmd);

#endif
