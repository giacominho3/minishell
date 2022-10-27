/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 07:59:54 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/27 08:27:52 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

struct s_env	*find_by_name(struct s_env **head, char *name)
{
	/* search the env looking for the node with a certain name, if params
	are not valid or the function dosen't find a node with the same name
	it reurns NULL */
	struct s_env	*to_find;

	if ((*head) == NULL || name == NULL)
	{
		printf("find_by_name: invalid params\n");
		return (NULL);
	}
	to_find = (*head);
	while (to_find != NULL)
	{
		if (to_find->name == name)
			return (to_find);
		to_find = to_find->next;
	}
	return (NULL);
}

void	print_node(struct s_env **head, char *name, int print)
{

	struct s_env	*to_print;

	to_print = find_by_name(head, name);
	if (print == 0 || print == NULL)
		printf("%s", to_print->content);
	else if (print == 1)
		printf("%s=%s", to_print->name, to_print->content);
}
