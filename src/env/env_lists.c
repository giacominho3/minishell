/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:03:21 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/08 17:29:04 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	free_env_node(t_env *node)
{
	t_env	*prev;

	prev = node->prev;
	prev->next = node->next;
	ft_free(node->name);
	ft_free(node->content);
	ft_free(node);
}

void	ft_add_last(struct s_env **head, char *str)
{
	struct s_env	*new;
	struct s_env	*last;

	last = (*head);
	new = (struct s_env *)ft_malloc(sizeof(struct s_env));
	ft_set_data(new, str);
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

void	ft_add_after(struct s_env *prev_node, char *str)
{
	struct s_env	*new;

	if (prev_node == NULL)
	{
		printf("ft_add_before: invalid prev node\n");
		return ;
	}
	new = (struct s_env *)ft_malloc(sizeof(struct s_env));
	ft_set_data(new, str);
	new->next = prev_node->next;
	prev_node->next = new;
	new->prev = prev_node;
	if (new->next != NULL)
		new->next->prev = new;
}

void	ft_add_before(struct s_env *next_node, char *str)
{
	struct s_env	*new;

	if (next_node == NULL)
	{
		printf("ft_add_before: invalid prev node\n");
		return ;
	}
	new = (struct s_env *)ft_malloc(sizeof(struct s_env));
	ft_set_data(new, str);
	new->next = next_node;
	new->prev = next_node->prev;
	next_node->prev->next = new;
	next_node->prev = new;
}

void	clear_env(struct s_env **head)
{
	struct s_env	*current;
	struct s_env	*next;

	current = (*head);
	while (current != NULL)
	{
		next = current->next;
		ft_free(current);
		current = next;
	}
	(*head) = NULL;
}
