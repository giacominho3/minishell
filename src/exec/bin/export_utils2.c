/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 04:58:14 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 01:01:49 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/builtins.h"

void	ft_set_export_data(t_export *node, char *str)
{
	if (!find_char_instr('=', str))
	{
		node->name = ft_get_name(str, 61);
		node->content = NULL;
		return ;
	}
	node->name = ft_get_name(str, 61);
	node->content = ft_get_content(str, 61);
}

/**
 * @brief add a node to the end of the export list
 */
void	ft_add_export(t_export **head, char *str)
{
	t_export	*new;
	t_export	*last;

	last = (*head);
	new = (t_export *)ft_malloc(sizeof(t_export));
	if (!new)
	{
		printf("add_last: error while allocating new node: str(%s)\n", str);
		return ;
	}
	ft_set_export_data(new, str);
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

void	copy_env_to_export(t_export **head, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_add_export(head, envp[i]);
		i++;
	}
}
