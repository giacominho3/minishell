#include "../../_incl/tokens.h"

/**
 * @param current_char char of the cmd string that is being analyzed
 * @return number of chars that compose the redirection
 *
 * @brief function that scans the cmd string to find if there are redirections
 */
int	scan_redirections(char *cmd, int i, t_token_list **tok_head)
{
	char	*tmp;

	if (cmd[i] == 60)
	{
		if (cmd[i + 1] == 60)
		{
			tmp = get_redir(cmd, i, 2);
			ft_add_tok_last(tok_head, TOK_HEREDOC, tmp);
			free(tmp);
			return (i + 2);
		}
		tmp = get_redir(cmd, i, 1);
		ft_add_tok_last(tok_head, TOK_REDIRECTION, tmp);
		free(tmp);
		return (i + 1);
	}
	return (i);
}

/**
 * @param cmd string to be tokenized
 * @param i index where the tokenizer is arrived
 * @param tok_head head_ref to the token list
 * @return new index where the tokenization is arrived
 *
 * @brief looks for elements that can be found in the head of a cmd line
 * for now scans just the redirections / heredoc
 */
int	head_scan(char *cmd, int i, t_token_list **tok_head)
{
	int	new_index;

	new_index = i;
	while (cmd[i])
	{
		i = new_index;
		new_index = scan_redirections(cmd, new_index, tok_head);
		if (i > new_index)
			break;
	}
	return (i);
}

int	scan_cmd(char *cmd, int i, t_token_list **tok_head)
{

	if ()
}

int	body_scan(char *cmd, int i, t_token_list **tok_head)
{
	int	new_index;

	new_index = i;
	while (cmd[i])
	{
		i = new_index;
		new_index = scan_cmd();
		new_index = scan_flags();
		new_index = scan_args();
		if (i > new_index)
			break ;
	}
	return (new_index);
}
