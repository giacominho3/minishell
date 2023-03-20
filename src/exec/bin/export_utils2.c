/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 04:58:14 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 18:51:20 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/builtins.h"

/**
 * @param arg
 *
 * @brief check if the arg is valid to be added also to the env
 */
int	not_valid_for_env(char *arg)
{
	if (is_in_strings(61, arg))
		return (0);
	return (1);
}

/**
 * @brief check if the arg of a command
 * is valid to be added to the export
 */
int	check_if_valid(char *arg)
{
	if ((arg[0] >= 65 && arg[0] <= 90)
		|| (arg[0] >= 97 && arg[0] <= 122) || arg[0] == 95)
		return (0);
	return (1);
}

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
