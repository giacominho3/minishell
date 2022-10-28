/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:08:38 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/25 19:28:26 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	quotes_syntax(char *str, char c)
{
	/* generalized function to check if a char is opened and closed (used for quotes) */
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while(str[i])
	{
		if (str[i] == c)
			quotes++;
		i++;
	}
	if ((quotes % 2) == 0)
		return (0);
	return (1);
}

bool	is_valid_syntax(char *str)
{
	/* function to check that the input taken contains just valid characters */
	int		i;

	i = 0;
	while(str[i])
	{
		if (!((str[i] >= 32 && str[i] <= 126) || str[i] == 10))
			return (false);
		i++;
	}
	return (true);
}

int	syntax(char *str)
{
	/* wrapper function for syntax checks */
	if (!is_valid_syntax(str))
	{
		printf("Minishell: syntax error: invalid character\n");
		return (1);
	}
	if (quotes_syntax(str, 34))
	{
		printf("Minishell: syntax error: double quotes opened but not closed\n");
		return (1);
	}
	if (quotes_syntax(str, 39))
	{
		printf("Minishell: syntax error: single quotes opened but not closed\n");
		return (1);
	}
	return (0);
}
