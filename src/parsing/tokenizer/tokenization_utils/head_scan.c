/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_scan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:20:11 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/13 02:23:15 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_incl/tokens.h"

char	*get_limiter(char *cmd, int index)
{
	int		len;
	int		i;
	int		new_index;
	char	*limiter;

	new_index = index + 2;
	while (cmd[new_index] == 32 && cmd[new_index])
		new_index++;
	len = new_index;
	while (cmd[len] && !is_metacharacter(cmd[len]))
		len++;
	limiter = ft_malloc((len - index + 2) + 1);
	i = 0;
	while (cmd[new_index] && !is_metacharacter(cmd[new_index])
		&& !is_skippable(cmd[new_index]))
	{
		limiter[i] = cmd[new_index];
		new_index++;
		i++;
	}
	limiter[i] = 0;
	return (limiter);
}

int	heredoc_skip(char *cmd, int i)
{
	int	tmp_index;

	tmp_index = i;
	tmp_index += 2;
	while (cmd[tmp_index] == 32)
		tmp_index++;
	while (cmd[tmp_index] && !is_metacharacter(cmd[tmp_index])
		&& !is_skippable(cmd[tmp_index]))
			tmp_index++;
	return (tmp_index);
}

int	redir_skip(char *cmd, int i)
{
	int	tmp_index;

	tmp_index = i + 1;
	while (cmd[tmp_index] == 32)
		tmp_index++;
	while (cmd[tmp_index] && (!is_metacharacter(cmd[tmp_index])
			|| !is_skippable(cmd[tmp_index])) && cmd[tmp_index] != 32)
		tmp_index++;
	return (tmp_index - 1);
}

/**
 * @param current_char char of the cmd string that is being analyzed
 * @return number of chars that compose the redirection
 *
 * @brief function that scans the cmd string to find if there are redirections
 */
int	scan_redirections(char *cmd, int i, t_token_list **tok_head)
{
	char	*tmp;
	int		new_index;

	new_index = i;
	new_index += skip_intial_spaces(cmd);
	if (cmd[new_index] == 60 && cmd[new_index + 1] == 60)
	{
		tmp = get_limiter(cmd, new_index);
		heredoc(tmp, new_index, tok_head);
		ft_free(tmp);
		return (heredoc_skip(cmd, new_index));
	}
	if (cmd[new_index] == 60 || cmd[new_index] == 62)
	{
		tmp = get_redir(cmd, new_index);
		ft_add_tok_last(tok_head, TOK_REDIRECTION, tmp);
		ft_free(tmp);
		return (redir_skip(cmd, new_index) + 1);
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
