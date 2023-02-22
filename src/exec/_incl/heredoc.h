#ifndef MINISHELL_HEREDOC_H
# define MINISHELL_HEREDOC_H
# include "../../../incl/minishell.h"

void	heredoc(char *cmd, int index, t_token_list **tok_head);
void	clear_heredoc(t_cmd *cmd_head);

#endif //MINISHELL_HEREDOC_H
