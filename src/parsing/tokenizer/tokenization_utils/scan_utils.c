/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:23:27 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 10:20:56 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_incl/tokens.h"

char	*get_redir(char *cmd, int i)
{
	char	*ret;
	int		index;
	int		len;
	char	c;

	c = cmd[i];
	i++;
	while (cmd[i] && (cmd[i] == 32 || cmd[i] == 9))
		i++;
	len = 0;
	index = i;
	while (cmd[index] && !is_metacharacter(cmd[i]))
	{
		len++;
		index++;
	}
	ret = ft_malloc(len + 2);
	ret[0] = c;
	index = 1;
	while (cmd[index] && !is_metacharacter(cmd[i]))
		ret[index++] = cmd[i++];
	ret[index] = 0;
	return (ret);
}

char	*get_heredoc(char *cmd, int i)
{
	char	*ret;
	int		index;
	int		len;

	i += 2;
	while (cmd[i] && (cmd[i] == 32 || cmd[i] == 9))
		i++;
	len = 0;
	index = i;
	while (cmd[index] && !is_metacharacter(cmd[i]))
	{
		len++;
		index++;
	}
	ret = ft_malloc(len + 3);
	ret[0] = '<';
	ret[1] = '<';
	index = 2;
	while (cmd[i] && (cmd[i] == 32 || cmd[i] == 9))
		ret[index++] = cmd[i++];
	while (cmd[i] && !is_metacharacter(cmd[i]))
		ret[index++] = cmd[i++];
	ret[index] = 0;
	return (ret);
}

bool	not_operator(char c)
{
	if (c != 60 && c != 62 && c != 124)
		return (true);
	return (false);
}

int	calc_arg_len(char *cmd, int i)
{
	int		cont;
	bool	single_q;
	bool	double_q;

	cont = 0;
	single_q = false;
	double_q = false;
	while (cmd[i] != 0 && not_operator(cmd[i]) && !is_metacharacter(cmd[i]))
	{
		if ((single_q == false && double_q == false) && cmd[i] == 32)
			break ;
		if (cmd[i] == 39)
				single_q = !single_q;
		if (cmd[i] == 34)
			double_q = !double_q;
		if (cmd[i] == 45 && !single_q && !double_q)
			break ;
		cont++;
		i++;
	}
	return (cont);
}

/**
 * @param str string
 * @param i string index
 *
 * @brief gives the new index for the first
 * non-space char after the given index
 */
int	skip_spaces(char *str, int i)
{
	while (str[i] && !is_metacharacter(str[i]) && is_skippable(str[i]))
		i++;
	return (i);
}
