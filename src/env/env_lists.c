/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:03:21 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/26 18:14:09 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	ft_add_front(struct s_env **head, char *name, char *content)
{
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

void	ft_add_before()
{

}

void	ft_add_before()
{

}

int main(void)
{
	struct s_env *list = NULL;

	ft_add_front(&list, "gugu", "gaga");
	ft_add_front(&list, "suca", "melo");

	list = list->next;
	printf("next name: %s | content: %s\n", list->name, list->content);
	list = list->prev;
	printf("head name: %s | content: %s\n", list->name, list->content);

}