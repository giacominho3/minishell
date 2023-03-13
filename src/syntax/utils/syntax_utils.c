/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 01:17:41 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 01:23:06 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/minishell.h"

int	print_syntax_err(int cont_open, int cont_close, char open, char close)
{
	if (cont_open > cont_close)
		printf("test: Minishell: syntax: '%c' opened but not closed\n",
			open);
	if (cont_open < cont_close)
		printf("test: Minishell: syntax: '%c' closed but not opened\n",
			close);
	return (1);
}

/**
 *
 * @param str string to check
 * @param quote type of quote to check
 * @return 1 if each open occurrence isn't matched with a close char
 *
 * @brief check that every occurrence of a quote is closed
 */
int	open_quotes_syntax(char *str, char quote)
{
	int		i;
	int		cont;
	bool	in_single;
	bool	in_double;

	i = 0;
	cont = 0;
	while (str[i])
	{
		if (str[i] == 39 && !in_single)
			in_double = !in_double;
		if (str[i] == 34 && !in_double)
			in_single = !in_single;
		if (str[i] == quote && (!in_double || !in_single))
		{
			cont++;
			i++;
			continue ;
		}
		i++;
	}
	if ((cont % 2) == 0)
		return (0);
	return (1);
}

/**
 * @param string string to check
 * @param open
 * @param close
 *
 * @brief check that every open char is matched by one close char
 */
int	open_char_syntax(char *string, char open, char close)
{
	int	i;
	int	cont_open;
	int	cont_close;

	i = 0;
	cont_close = 0;
	cont_open = 0;
	while (string[i])
	{
		if (string[i] == open)
			cont_open++;
		if (string[i] == close)
			cont_close++;
		i++;
	}
	if (cont_open != cont_close)
		return (print_syntax_err(cont_open, cont_close, open, close));
	return (0);
}

/**
 * @param str string to check
 * @return true if the string is valid, and false if it contains invalid chars
 *
 * @brief to check that the input taken contains just valid characters
 */
bool	is_valid_syntax(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 32 && str[i] <= 126) || str[i] == 10 || str[i] == 9))
			return (false);
		i++;
	}
	return (true);
}

int	pipe_appended(char *string, char pipe)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == pipe && string[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}
