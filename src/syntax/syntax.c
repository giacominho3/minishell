/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:08:38 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/13 01:22:53 by gifulvi         ###   ########.fr       */
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
		printf(SYNTAX_ERR_PIPE);
		return (1);
	}
	if (open_char_syntax(str, 40, 41))
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
int	check_redir_name(char *str, int i)
{
	int	j;

	j = i;
	j = skip_spaces(str, j);
	if (is_metacharacter(str[j])
		|| is_in_strings(str[j], "?$|=/"))
		return (1);
	return (0);
}

int	redir_syntax_err(char *err_msg, int ret_val)
{
	printf("%s", err_msg);
	return (ret_val);
}

int	redirections_syntax(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 62)
		{
			if (str[i + 1] == 62 || check_redir_name(str, i +1))
				return (redir_syntax_err(SYNTAX_ERR_REDIR, 1));
		}
		if (str[i] == 60)
		{
			if (str[i + 1] == 60)
			{
				if (check_redir_name(str, i + 2) || str[i + 2] == 60)
					return (redir_syntax_err(SYNTAX_ERR_REDIR, 1));
			}
		}
	}
	return (0);
}

/* wrapper function for syntax checks */
int	syntax(char *str)
{
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
