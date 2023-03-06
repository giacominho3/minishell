/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_len_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:36:42 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/26 09:15:36 by tterribi         ###   ########.fr       */
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
//		printf("curr char: %c\n", parse->input[i]);
		expand_check(parse, i);
		if (parse->input[i] == 36 && parse->extend
			&& valid_var_name(parse->input[i+1]))
		{
			len += get_content_len(parse, head, i + 1);
//			printf("len: %d\n", len);
			i += 1 + var_name_len(parse->input, i + 1);
//			printf("i: %d\n", i);
			continue ;
		}
		len++;
		i++;
	}
	return (len);
}

/**
 * @brief gets the len of the content of an env's var
 */
int get_content_len(t_parse *parse, struct s_env **head, int offset)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = offset;
	printf("FIRST CHAR OF THE VAR NAME[%d]: %c\n", offset, parse->input[offset]);
	printf("offset: %d\n", offset);
	printf("VAR NAME LEN: %d\n", var_name_len(parse->input, offset) + 1);
	buf = ft_malloc(var_name_len(parse->input, offset) + 1);
	if (!buf)
		return (0);
	while (parse->input[j] && !var_end_name(parse->input[j]))
		buf[i++] = parse->input[j++];
	buf[i] = 0;
	printf("buf: %s\n", buf); //debug print
	i = ft_strlen(get_content_by_name(head, buf));
	printf("get_content_by_name output: %s\n", get_content_by_name(head, buf)); //debug print
	printf("get_content_len output: %d\n", i); //debug print
	free(buf);
	return (i);
}
