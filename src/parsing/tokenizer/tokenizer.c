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
	print_token_lists(cmd_head);
	return (0);
}

void	print_toks(t_token_list **head)
{
	t_token_list	*tmp;

	printf("___TOKS PRINT___\n");
	tmp = (*head);
	while (tmp != NULL)
	{
		printf("%s : %d (ascii val: %d)\n", tmp->token, tmp->type, tmp->token[0]);
		tmp = tmp->next;
	}
	printf("________________\n");
}

/**
 * @param head head of the command list
 *
 * @brief all the tokens lists of each command
 */
void	print_token_lists(t_cmd **head)
{
	t_cmd *tmp;
	int i = 1;

	if ((*head) == NULL)
		return ;
	tmp = (*head);
	printf("TOK_CMD: %d\n", TOK_CMD);
	printf("TOK_FLAGS: %d\n", TOK_FLAGS);
	printf("TOK_HEREDOC: %d\n", TOK_HEREDOC);
	printf("TOK_REDIRECTION: %d\n", TOK_REDIRECTION);
	printf("TOK_ARGS: %d\n", TOK_ARGS);
	printf("TOK_PREV_LOGIC_OP: %d\n", TOK_PREV_LOGIC_OP);
	printf("TOK_NEXT_LOGIC_OP: %d\n", TOK_NEXT_LOGIC_OP);
	printf("TOK_IN_FILE: %d\n", TOK_IN_FILE);
	printf("TOK_OUT_FILE: %d\n", TOK_OUT_FILE);
	printf("TOK_ERROR: %d\n", TOK_ERROR);
	while (tmp != NULL)
	{
		printf("token list of cmd %d:\n", i);
		print_toks(&tmp->tok_head);
		printf("--------------------------\n");
		tmp = tmp->next;
	}
}
