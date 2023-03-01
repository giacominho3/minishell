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

/* wrapper function for characters that can be opened such abb quotes */
int	open_char_wrapper(char *str)
{
	if (open_quotes_syntax(str, 34))
	{
		printf(SYNTAX_ERR_DQUOT);
		return (1);
	}
	if (open_quotes_syntax(str, 39))
	{
		printf(SYNTAX_ERR_SQUOT);
		return (1);
	}
	if (pipe_appended(str, 124))
	{

		return (1);
	}
	if (open_char_syntax(str, 40, 41))
		return (1);
	return (0);
}

int	ft_isprint(int arg)
{
	if (arg >= 32 && arg <= 126)
		return (1);
	return (0);
}

/**
 *
 * @param str
 * @param i
 *
 * @brief check if the name of the file
 * used/created by the redirection contains only valid chars
 */
int check_redir_name(char *str, int i)
{
	int	j;

	j = i;

	j = skip_spaces(str, j);
	if (is_metacharacter(str[j])
		|| is_in_strings(str[j], "?$|=/"))
		return (1);
	return (0);
}

int	redirections_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 62)
		{
			if (str[i + 1] == 62 || check_redir_name(str, i +1))
			{
				printf(SYNTAX_ERR_REDIR);
				return (1);
			}
		}
		if (str[i] == 60)
		{
			if (str[i + 1] == 60)
			{
				if (check_redir_name(str, i + 2) || str[i + 2] == 60)
				{
					printf(SYNTAX_ERR_REDIR);
					return (1);
				}
			}
		}
		i++;
	}
	return (0);
}

/* wrapper function for syntax checks */
int	syntax(char *str)
{
//	if (ft_strlen(str) <= 1)
//	{
//		printf("Minishell: Bad address\n");
//		return (1);
//	}
	if (!is_valid_syntax(str))
	{
		printf(SYNTAX_ERR_INVALID_CHAR);
		return (1);
	}
	if (open_char_wrapper(str))
		return (1);
	if (redirections_syntax(str))
		return (1);
	return (0);
}
