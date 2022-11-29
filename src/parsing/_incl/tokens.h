#ifndef MINISHELL_TOKENS_H
# define MINISHELL_TOKENS_H
# include "../../../incl/minishell.h"

int		scan_reidrections(char *string, int offset, t_token_list **head);
int		tokenizer(t_cmd **cmd_head);
char	*get_tok_content_by_type(t_token_list **head, t_tokens type);

#endif
