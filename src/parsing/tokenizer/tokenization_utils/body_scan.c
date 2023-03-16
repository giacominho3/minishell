/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   body_scan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:10:33 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 10:32:52 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_incl/tokens.h"

int	scan_cmd(char *cmd, int i, t_token_list **tok_head)
{
	int		new_index;
	char	*tok_cpy;
	int		tok_index;

	if (cont_tok_by_type(tok_head, TOK_CMD) > 0)
		return (i);
	while (is_skippable(cmd[i]))
		i++;
	new_index = i;
	tok_index = 0;
	tok_cpy = ft_malloc(calc_tok_len(cmd, i) + 1);
	while (cmd[new_index] && !is_metacharacter(cmd[new_index])
		&& !is_skippable(cmd[new_index]))
	{
		tok_cpy[tok_index] = cmd[new_index];
		new_index++;
		tok_index++;
	}
	tok_cpy[tok_index] = 0;
	ft_add_tok_last(tok_head, TOK_CMD, tok_cpy);
	ft_free(tok_cpy);
	return (new_index);
}

int	scan_flags(char *cmd, int i, t_token_list **tok_head)
{
	int		new_index;
	char	*tok_cpy;
	int		tok_index;

	while (is_skippable(cmd[i]))
		i++;
	if (cmd[i] != 45)
		return (i);
	new_index = i;
	tok_index = 0;
	tok_cpy = ft_malloc(calc_tok_len(cmd, i));
	while (cmd[new_index] && !is_metacharacter(cmd[new_index])
		&& !is_skippable(cmd[new_index]))
	{
		tok_cpy[tok_index] = cmd[new_index];
		new_index++;
		tok_index++;
	}
	tok_cpy[tok_index] = 0;
	ft_add_tok_last(tok_head, TOK_FLAGS, tok_cpy);
	ft_free(tok_cpy);
	new_index = scan_flags(cmd, new_index, tok_head);
	return (new_index);
}

int	copy_tok(char *cmd, int new_index, int len, char *tok_cpy)
{
	int		tok_index;
	bool	sq;
	bool	dq;

	tok_index = 0;
	sq = false;
	dq = false;
	while (cmd[new_index] && tok_index < len
		&& !is_metacharacter(cmd[new_index]) && invalid_pipe(cmd, new_index))
	{
		if ((sq == false && dq == false) && cmd[new_index] == 32)
			break ;
		if (cmd[new_index] == 34 && !dq)
			sq = !sq;
		if (cmd[new_index] == 34 && !sq)
			dq = !dq;
		tok_cpy[tok_index++] = cmd[new_index++];
	}
	tok_cpy[tok_index] = 0;
	return (new_index);
}

int	scan_args(char *cmd, int i, t_token_list **tok_head)
{
	int		new_index;
	char	*tok_cpy;
	int		len;

	if (cmd[i] && !is_metacharacter(cmd[i]))
	{
		i = skip_spaces(cmd, i);
		new_index = i;
		printf("new index: %d(char: %c)", new_index, cmd[new_index]);
		len = calc_arg_len(cmd, i);
		tok_cpy = ft_malloc(len);
		new_index = copy_tok(cmd, new_index, len, tok_cpy);
		if (ft_strlen(tok_cpy) >= 1)
			ft_add_tok_last(tok_head, TOK_ARGS, tok_cpy);
		ft_free(tok_cpy);
		return (new_index);
	}
	return (i);
}

/**
 * @param cmd string to be tokenized
 * @param i index where the tokenizer is arrived
 * @param tok_head head_ref to the token list
 * @return new index where the tokenization is arrived
 *
 * @brief looks for elements that can be found in the body of a cmd line
 * for now scans just the commands, flags and args
 */
int	body_scan(char *cmd, int i, t_token_list **tok_head)
{
	int	new_index;

	new_index = i;
	if (cmd[i])
	{
		new_index = scan_cmd(cmd, new_index, tok_head);
		new_index = scan_flags(cmd, new_index, tok_head);
		new_index = scan_args(cmd, new_index, tok_head);
	}
	return (new_index);
}
