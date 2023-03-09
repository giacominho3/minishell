#ifndef PIPELINE_H
# define PIPELINE_H
# include "../../../incl/minishell.h"

# define READ 0
# define WRITE 1

void	pipeline_wrapper(t_main *main);

int		calc_env_y(t_env **env_head);
int		calc_env_x(t_env **env_head);
char	**fill_env_mat(t_env **env_head);

#endif
