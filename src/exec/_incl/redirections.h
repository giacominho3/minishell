#ifndef MINISHELL_REDIRECTIONS_H
# define MINISHELL_REDIRECTIONS_H
# include "../../../incl/minishell.h"

void	ft_heredoc(t_token_list **head, char *limiter);
int		ft_inReidirect(char *cmd, int i);
void	ft_outReidirect(t_token_list **head, char *file);
#endif
