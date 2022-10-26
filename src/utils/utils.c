/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:23:50 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/26 12:24:14 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
