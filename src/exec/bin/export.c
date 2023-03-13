/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 04:56:33 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/12 05:00:00 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/builtins.h"

void	clear_export(t_export **head)
{
	t_export	*current;
	t_export	*next;

	current = (*head);
	while (current != NULL)
	{
		next = current->next;
		ft_free(current);
		current = next;
	}
	(*head) = NULL;
}

void	print_export(t_cmd *cmd)
{
	t_export	*curr;

	curr = cmd->main_ref->export_head;
	while (curr != NULL)
	{
		printf("declare -x %s", curr->name);
		if (curr->content != NULL)
			printf("=\"%s\"", curr->content);
		printf("\n");
		curr = curr->next;
	}
}

int	export_printing(t_cmd *cmd)
{
	print_export(cmd);
	exit (EXIT_SUCCESS);
}

int	builtin_export(t_cmd *cmd)
{
	add_elements_to_export(cmd);
	return (0);
}
