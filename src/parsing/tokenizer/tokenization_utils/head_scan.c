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
	int		ret;

	if (cmd[i] == 60 || cmd[i] == 62)
	{
		if (cmd[i] == 60 && cmd[i + 1] == 60)
		{
			tmp = get_heredoc(cmd, i);
			ft_add_tok_last(tok_head, TOK_HEREDOC, tmp);
			ret = ft_strlen(tmp);
			free(tmp);
			return (i + ret);
		}
		tmp = get_redir(cmd, i);
		ft_add_tok_last(tok_head, TOK_REDIRECTION, tmp);
		ret = ft_strlen(tmp);
		free(tmp);
		return (i + ret);
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

	write(1, "a\n", 2);
	i = new_index;
	new_index += scan_redirections(cmd, new_index, tok_head);
	return (new_index);
}

