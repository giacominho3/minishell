/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:14:43 by tterribi          #+#    #+#             */
/*   Updated: 2022/11/03 03:25:24 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/minishell.h"

/*
 * What I have to handle:
 * Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
 * Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence
 * except for $ (dollar sign).
*/

void	ft_extend(char *str, struct s_cmd *node, int index)
{
	



}

char	*quotes_handler(char *str, struct s_cmd *node)
{
	int		i;
	bool	extend;
	bool	single_quotes;
	bool	double_quotes;

	i = 0;
	extend = true;
	single_quotes = false;
	double_quotes = false;
	while (str[i])
	{
		if (str[i] == 34)
			double_quotes = true;
		if (str[i] == 39)
			single_quotes = true;
		if (str[i] == 36)
			ft_extend(str, node, i);
		i++;
	}
}
