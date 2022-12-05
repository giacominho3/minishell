/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 07:59:54 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/27 12:39:51 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

/* search the env looking for the node with a certain name, if params
* are not valid or the function doesn't find a node with the same name
* it returns NULL */
char	*get_content_by_name(struct s_env **head, char *name)
{
	struct s_env	*to_find;

	if ((*head) == NULL || name == NULL)
	{
		printf("find_by_name: invalid params\n");
		return (NULL);
	}
	to_find = (*head);
	while (to_find != NULL)
	{
		if (ft_strcmp(to_find->name , name) == 0)
			return (to_find->content);
		to_find = to_find->next;
	}
	return ("");
}

void	print_env(struct s_env **head)
{
	struct s_env *tmp;
	int i = 0;

	tmp = (*head);
	while (tmp != NULL)
	{
		printf("[%d]%s=%s\n", i, tmp->name, tmp->content);
		i++;
		tmp = tmp->next;
	}
}

/* this function prints a specific node (found by his name) */
//void	print_node(struct s_env **head, char *name, int print)
//{
//	struct s_env	*to_print;
//
//	to_print = find_by_name(head, name);
//	if (print == 0)
//		printf("%s", to_print->content);
//	else if (print == 1)
//		printf("%s=%s", to_print->name, to_print->content);
//}
