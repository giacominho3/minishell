/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:52:19 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/13 02:52:22 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	ft_mat_col(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count - 1);
}

int	ft_mat_row(char **matrix)
{
	int	y;
	int	x;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
			x++;
		y++;
	}
	return (y - 1);
}
