/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:06:15 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 02:06:48 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/minishell.h"

/**
 * @param sub_string = current analyzed command
 * @param head = head to the token list of the current cmd list node
 *
 * @brief functions acts like a wrapper for some sub-functions that are going to
 * search for specifics types of tokens inside the command passed abb a parameter
 * and returns a pointer to the head of the list of tokens for that command
 */
void	_tokenizer(char *cmd, t_token_list **tok_head)
{
	int	i;

	i = 0;
	while (cmd[i] && cmd [i] != '|' && cmd[i + 1] != '|')
	{
		i = head_scan(cmd, i, tok_head);
		i = body_scan(cmd, i, tok_head);
		i = tail_scan(cmd, i, tok_head);
		if (!cmd[i])
			break ;
	}
}

/**
 * @param cmd_head head to the command list
 *
 * @brief wrapper function for the tokenizer
 */
int	tokenizer(t_cmd **cmd_head)
{
	t_cmd	*curr;

	curr = (*cmd_head);
	while (curr != NULL)
	{
		_tokenizer(curr->cmd, &curr->tok_head);
		curr = curr->next;
	}
	return (0);
}
