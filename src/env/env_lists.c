/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:03:21 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/26 19:53:27 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	ft_add_front(struct s_env **head, char *name, char *content)
{
	//add a node at the beginning of the list
	struct s_env	*new;

	new = (struct s_env *)malloc(sizeof(struct s_env));
	if (!new)
	{
		printf("add_front: error while allocating new node: name(%s)\n", name);
		return ;
	}
	new->name = name;
	new->content = content;
	new->next = (*head);
	new->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new;
	(*head) = new;
}

void	ft_add_last(struct s_env **head, char *name, char *content)
{
	//add a node to the end of the list
	struct s_env	*new;
	struct s_env	*last;

	last = (*head);
	new = (struct s_env *)malloc(sizeof(struct s_env));
	if (!new)
	{
		printf("add_last: error while allocating new node: name(%s)\n", name);
		return ;
	}
	new->name = name;
	new->content = content;
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

void	ft_add_after(struct s_env *prev_node, char *name, char *content)
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
	new->name = name;
	new->content = content;
	new->next = prev_node->next;
	prev_node->next = new;
	new->prev = prev_node;
	if (new->next != NULL)
		new->next->prev = new;
}

void ft_add_before(struct s_env *next_node, char *name, char *content)
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
	new->name = name;
	new->content = content;
	new->next = next_node;
	new->prev = next_node->prev;
	next_node->prev->next = new;
	next_node->prev = new;
}

void	print_list(struct s_env **head)
{
	//prints the whole linked list
	struct s_env *tmp;

	tmp = (*head);
	while (tmp != NULL)
	{
		printf("%s: %s\n", tmp->name, tmp->content);
		tmp = tmp->next;
	}
}

int main(void)
{
	struct s_env *list = NULL;

	ft_add_front(&list, "gugu", "gaga");
	ft_add_front(&list, "suca", "melo");
	ft_add_after(list->next, "among", "us");
	ft_add_before(list->next, "nicco nicco", "niiiiii");
	ft_add_last(&list, "pray the sun", "bitch");
	print_list(&list);
}