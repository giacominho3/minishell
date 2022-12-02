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
	return (0);
}
