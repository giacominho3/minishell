#ifndef MINISHELL_COMMANDS_H
# define MINISHELL_COMMANDS_H
# include "../../../incl/minishell.h"

struct s_main;

void	add_cmd_last(struct s_cmd **head, char *cmd);
int		command_splitter(char *input, struct s_main *main);
void	ft_cmdcpy(char *dest, const char *src, int len, int offset);
bool	cmd_split(char *str, int index);
int		cmd_len(char *input, int offset);
void	clear_cmd_list(struct s_cmd **head);


//debug
void	print_cmd(struct s_cmd **head);

#endif