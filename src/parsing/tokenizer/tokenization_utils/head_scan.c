#include "../../_incl/tokens.h"

int	heredoc_skip(char *cmd, int i)
{
	int tmp_index;

	tmp_index = i;
	tmp_index += 2;
	while (cmd[tmp_index] == 32)
		tmp_index++;
	printf("REDIR_SKIP\n");
	while(cmd[tmp_index] && !is_metacharacter(cmd[tmp_index])
		&& !is_skippable(cmd[tmp_index]))
	{
		printf("|%c|\n", cmd[tmp_index]);
		tmp_index++;
	}
	printf("-------------\n");
	return(tmp_index);
}

int	redir_skip(char *cmd, int i)
{
	int tmp_index;

	tmp_index = i+1;
	while (cmd[tmp_index] == 32)
		tmp_index++;
	printf("cursor at index: %d (char: %c)\n", tmp_index, cmd[tmp_index]);
	while(cmd[tmp_index] && !is_metacharacter(cmd[tmp_index])
		  && !is_skippable(cmd[tmp_index]))
	{
		printf("|%c|\n", cmd[tmp_index]);
		tmp_index++;
	}
	printf("-------------\n");
	printf("tmp_index: %d (char: %c)\n", tmp_index - 1, cmd[tmp_index - 1]);
	return(tmp_index - 1);
}

/**
 * @param current_char char of the cmd string that is being analyzed
 * @return number of chars that compose the redirection
 *
 * @brief function that scans the cmd string to find if there are redirections
 */
int scan_redirections(char *cmd, int i, t_token_list **tok_head)
{
	char	*tmp;
	int		new_index;

	new_index = i;
	new_index += skip_intial_spaces(cmd);
	if (cmd[new_index] == 60 && cmd[new_index + 1] == 60)
	{
		tmp = get_heredoc(cmd, new_index);
		ft_add_tok_last(tok_head, TOK_HEREDOC, tmp);
		free(tmp);
		return (heredoc_skip(cmd, new_index));
	}
	if (cmd[new_index] == 60 || cmd[new_index] == 62)
	{
		tmp = get_redir(cmd, new_index);
		ft_add_tok_last(tok_head, TOK_REDIRECTION, tmp);
		free(tmp);
		return (redir_skip(cmd, new_index));
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
	new_index = scan_redirections(cmd, new_index, tok_head);
	return (new_index);
}

