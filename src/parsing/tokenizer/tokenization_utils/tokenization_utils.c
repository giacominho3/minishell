/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:28:23 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 02:28:51 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_incl/tokens.h"

/**
 * @param c char to analyze
 * @return true if it's in the list of metacharacter, false if not
 *
 * @brief check if the char passed abb argument is a metacharacter
 */
bool	is_metacharacter(char c)
{
	if (c == 10 || c == 60
		|| c == 62)
		return (true);
	return (false);
}

bool	is_skippable(char c)
{
	if (is_in_strings(c, SPACE_CHARS))
		return (true);
	return (false);
}

/**
 * @param cmd cmd line string
 * @param i index to the beginning of the token
 *
 * @brief calculates the length of the token that have to
 * be inserted int he tok list
 */
int	calc_tok_len(char *cmd, int i)
{
	int	cont;

	cont = 0;
	while (cmd[i] && !is_metacharacter(cmd[i])
		&& !is_skippable(cmd[i]))
	{
		cont++;
		i++;
	}
	return (cont);
}
