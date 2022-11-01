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

/* wrapper function for characters that can be opened such as quotes */
int	open_char_wrapper(char *str)
{
	/* wrapper for open_char_syntax() */
	if (open_quotes_syntax(str, 34))
	{
		printf("Minishell: syntax error: double quotes opened but not closed\n");
		return (1);
	}
	if (open_quotes_syntax(str, 39))
	{
		printf("Minishell: syntax error: single quotes opened but not closed\n");
		return (1);
	}
	if (open_parenthesis_syntax(str, 40, 41))
	{
		printf("Minishell: syntax error: '(' opened but not closed\n");
		return (1);
	}
	if (open_parenthesis_syntax(str, 91, 92))
	{
		printf("Minishell: syntax error: '[' opened but not closed\n");
		return (1);
	}
	if (open_parenthesis_syntax(str, 123, 125))
	{
		printf("Minishell: syntax error: '{' opened but not closed\n");
		return (1);
	}
	return (0);
}

/* wrapper function for syntax checks */
int	syntax(char *str)
{
	if (!is_valid_syntax(str))
	{
		printf("Minishell: syntax error: invalid character\n");
		return (1);
	}
	if (open_char_wrapper(str))
		return (1);
	return (0);
}
