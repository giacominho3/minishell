/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_allocs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:55:19 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/25 17:56:03 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/minishell.h"

void	matrix_alloc(t_command *cmds, int cont_y, int max_x)
{
	int	i;

	cmds->commands = (char **)malloc(sizeof(char *) * cont_y + 1);
	i = 0;
	while (cmds->commands[i])
	{
		cmds->commands[i] = (char *)malloc(sizeof(char) * max_x);
		i++;
	}
	cmds->commands[cont_y + 1] = 0;
}

void	matrix_alloc_wrapper(char *str, t_command *cmds)
{
	int	i;
	int	j;
	int	cont_y;
	int	cont_x;
	int	max_x;

	i = 0;
	cont_x = 0;
	cont_y = 0;
	max_x = 0;
	while (str[i])
	{
		if (sep_conditions(str, i))
		{
			i += logic_skip(str, i);
			cont_y++;
			if (cont_x > max_x)
				max_x = cont_x;
		}
		cont_x++;
		i++;
	}
	cmds->mat_x = max_x;
	cmds->mat_y = cont_y;
	matrix_alloc(cmds, cont_y, max_x);
}
