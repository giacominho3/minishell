/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:06:15 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 10:31:13 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/minishell.h"

bool	invalid_pipe(char *cmd_line, int i)
{
	if (cmd_line[i] == '|' && (cmd_line[i - 1] != 34 && cmd_line[i - 1] != 92
			&& cmd_line[i - 1] != 39))
		return (false);
	if (cmd_line[i + 1] == '|' && (cmd_line[i] != 34 && cmd_line[i] != 39
			&& cmd_line[i - 1] != 92))
		return (false);
	return (true);
}

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
	i = skip_intial_spaces(cmd);
	while (cmd[i] && invalid_pipe(cmd, i))
	{
		i = head_scan(cmd, i, tok_head);
		printf("i val after head scan: %d\n", i);
		i = body_scan(cmd, i, tok_head);
		printf("i val after body scan: %d\n", i);
		i = tail_scan(cmd, i, tok_head);
		printf("i val after tail scan: %d\n", i);
		if (!cmd[i])
			break ;
	}
}

int	validate_cmd_tok(t_token_list **tok_head)
{
	t_token_list	*curr;

	curr = (*tok_head);
	while (curr != NULL)
	{
		if (curr->type == TOK_CMD)
			return (0);
		curr = curr->next;
	}
	return (1);
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
		if (validate_cmd_tok(&curr->tok_head))
		{
			perror("Minishell: no command found\n");
			curr->main_ref->exit_status = 127;
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}
