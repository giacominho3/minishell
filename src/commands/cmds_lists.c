/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:24:43 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/09 03:33:20 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	ft_set_cmd(t_cmd *node, t_main *main, char *cmd)
{
	if (!cmd)
		return ;
	node->tok_head = NULL;
	node->cmd = ft_strdup(cmd);
	node->main_ref = main;
}

void	add_cmd_last(t_cmd **head, t_main *main, char *cmd)
{
	t_cmd	*new;
	t_cmd	*last;

	last = (*head);
	new = (t_cmd *)ft_malloc(sizeof(t_cmd));
	ft_set_cmd(new, main, cmd);
	new->next = NULL;
	if ((*head) == NULL)
	{
		new->prev = NULL;
		(*head) = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
}

void	clear_cmd_list(t_cmd **head)
{
	t_cmd	*current;
	t_cmd	*next;

	current = (*head);
	while (current != NULL)
	{
		next = current->next;
		clear_tokens(&current->tok_head);
		if (current->cmd != NULL)
			ft_free(current->cmd);
		if (current != NULL)
			ft_free(current);
		current = next;
	}
	*head = NULL;
}

int	cont_cmd_number(t_cmd **cmd_head)
{
	t_cmd	*curr;
	int		cont;

	cont = 0;
	curr = (*cmd_head);
	while (curr != NULL)
	{
		cont++;
		curr = curr->next;
	}
	return (cont);
}
