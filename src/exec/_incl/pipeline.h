#ifndef MINISHELL_PIPELINE_H
# define MINISHELL_PIPELINE_H
# include "../../../incl/minishell.h"

# define READ 0
# define WRITE 1

void	pipeline(t_main *main);


int		calc_env_y(t_env **env_head);
int		calc_env_x(t_env **env_head);
char	**fill_env_mat(char **mat, t_env **env_head);

#endif
