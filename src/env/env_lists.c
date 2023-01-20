/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:03:21 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/27 12:50:53 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	ft_add_front(struct s_env **head, char *str)
{
	//add a node at the beginning of the list
	struct s_env	*new;

	new = (struct s_env *)malloc(sizeof(struct s_env));
	if (!new)
	{
		printf("add_front: error while allocating new node: str(%s)\n", str);
		return ;
	}
	ft_set_data(new, str);
	new->next = (*head);
	new->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new;
	(*head) = new;
}

void	free_env_node(t_env *node)
{
	t_env *prev;

	prev = node->prev;
	prev->next = node->next;
	free(node->name);
	free(node->content);
	free(node);
}

void	ft_add_last(struct s_env **head, char *str)
{
	//add a node to the end of the list
	struct s_env	*new;
	struct s_env	*last;

	last = (*head);
	new = (struct s_env *)malloc(sizeof(struct s_env));
	if (!new)
	{
		printf("add_last: error while allocating new node: str(%s)\n", str);
		return ;
	}
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
	//add a node after a given node
	struct s_env	*new;

	if (prev_node == NULL)
	{
		printf("ft_add_before: invalid prev node\n");
		return ;
	}
	new = (struct s_env*)malloc(sizeof(struct s_env));
	if (!new)
		return ;
	ft_set_data(new, str);
	new->next = prev_node->next;
	prev_node->next = new;
	new->prev = prev_node;
	if (new->next != NULL)
		new->next->prev = new;
}

void	ft_add_before(struct s_env *next_node, char *str)
{
	// add a new node before a given node
	struct s_env *new;

	if (next_node == NULL)
	{
		printf("ft_add_before: invalid prev node\n");
		return;
	}
	new = (struct s_env *)malloc(sizeof(struct s_env));
	if (!new)
		return;
	ft_set_data(new, str);
	new->next = next_node;
	new->prev = next_node->prev;
	next_node->prev->next = new;
	next_node->prev = new;
}

void clear_env(struct s_env **head)
{
	struct s_env	*current;
	struct s_env	*next;

	current = (*head);
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	(*head) = NULL;
}

