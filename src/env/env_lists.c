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

void	print_list(struct s_env **head)
{
	//prints the whole linked list
	struct s_env *tmp;
	int i = 0;

	tmp = (*head);
	while (tmp != NULL)
	{
		printf("%s=%s\n", tmp->name, tmp->content);
		tmp = tmp->next;
		i++;
	}
}

// int main(void)
// {
// 	struct s_env *list = NULL;

// 	printf("starting\n");
// 	ft_add_front(&list, "gugu=gaga");
// 	printf("add front 1 done\n");
// 	ft_add_front(&list, "suca=melo");
// 	printf("add front 2 done\n");
// 	ft_add_after(list->next, "among=us");
// 	ft_add_before(list->next, "nicco nicco=niiiiii");
// 	printf("add after done\n");
// 	ft_add_last(&list, "pray the sun=bitch");
// 	printf("add last done\n");
// 	printf("________print_list________\n");
// 	print_list(&list);
// }
