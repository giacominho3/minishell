#ifndef MINISHELL_EXEC_H
# define MINISHELL_EXEC_H
# include "../../../incl/minishell.h"

# define READ 0
# define WRITE 1

/**
 * Access
 */
int		execute(t_cmd *cmd, char **env_matrix);

/**
 * Access utils
 */
char	*find_cmd_path(t_cmd *cmd);
		char	*complete_path(char *src, t_cmd *cmd);
void	ft_free_matrix(char **matrix);
char	*complete_path(char *src, t_cmd *cmd);
void	args_format(t_cmd *cmd);


#endif //MINISHELL_EXEC_H
