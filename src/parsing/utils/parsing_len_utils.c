/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_len_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:36:42 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/13 19:50:15 by gifulvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/minishell.h"

/**
 * @brief when found a var counts the length of it's name
 * (doesn't count the $)
 */
int	var_name_len(char *string, int offset)
{
	int	len;

	len = 0;
	while (string[offset] && !var_end_name(string[offset]))
	{
		offset++;
		len++;
	}
	return (len);
}

/**
 * @brief calculates the len of the input once the vars are extended
 */
int	extended_len(t_parse *parse, t_env **head)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (parse->input[i])
	{
		expand_check(parse, i);
		if (parse->input[i] == 36 && parse->extend
			&& valid_var_name(parse->input[i + 1]) && parse->input[i - 1] != 92)
		{
			len += get_content_len(parse, head, i + 1);
			i += 1 + var_name_len(parse->input, i + 1);
			continue ;
		}
		if (!parse->back_slash)
			len++;
		i++;
	}
	return (len);
}

/**
 * @brief gets the len of the content of an env's var
 */
int	get_content_len(t_parse *parse, struct s_env **head, int offset)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = offset;
	buf = ft_malloc(var_name_len(parse->input, offset) + 1);
	if (!buf)
		return (0);
	while (parse->input[j] && !var_end_name(parse->input[j]))
		buf[i++] = parse->input[j++];
	buf[i] = 0;
	i = ft_strlen(get_content_by_name(head, buf));
	ft_free(buf);
	return (i);
}
