#ifndef MINISHELL_EXEC_H
# define MINISHELL_EXEC_H
# include "../../../incl/minishell.h"

# define READ 0
# define WRITE 1

char	*complete_path(char *src, t_cmd *cmd);
void	ft_free_matrix(char **matrix);
char	*complete_path(char *src, t_cmd *cmd);

#endif //MINISHELL_EXEC_H
