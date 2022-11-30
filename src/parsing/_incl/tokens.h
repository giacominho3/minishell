#ifndef MINISHELL_TOKENS_H
# define MINISHELL_TOKENS_H
# include "../../../incl/minishell.h"

int		scan_reidrections(char *cmd, int i, t_token_list **tok_head);
int		tokenizer(t_cmd **cmd_head);
void	ft_add_tok_last(t_token_list **head, t_tokens type, char *tok_val);
char	*ft_strndup(char *s, size_t n);
void	clear_tokens(t_token_list **head);
char	**ft_split_args(char *str);
void	print_token_lists(t_cmd **head);
#endif
