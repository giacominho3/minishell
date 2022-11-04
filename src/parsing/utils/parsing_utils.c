/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:19:08 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/25 19:54:28 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/minishell.h"

bool	sep_conditions(char *str, int index)
{
	if (str[index] == '|' && str[index + 1] == '|')
		return (true);
	if (str[index] == '&' && str[index + 1] == '&')
		return (true);
	if (str[index] == '|')
		return (true);
	return (false);
}

int	logic_skip(char *str, int index)
{
	if (str[index] == '|' && str[index + 1] == '|')
		return (2);
	if (str[index] == '&' && str[index + 1] == '&')
		return (2);
	if (str[index] == '|')
		return (1);
	return (0);
}
