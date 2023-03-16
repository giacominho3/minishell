/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:19:08 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 19:57:49 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/parse.h"

void	new_cmd_line(t_token_list *token, t_parse *parse)
{
	int	i;

	i = 0;
	token->token = ft_malloc(parse->out_len + 1);
	while (parse->out[i])
	{
		token->token[i] = parse->out[i];
		i++;
	}
	token->token[i] = 0;
}

/**
 * @brief check if a variable have to be extended or considering quotes
 */
void	expand_check(t_parse *parse, int i)
{
	if (parse->back_slash)
		parse->back_slash = false;
	if (parse->input[i] == 92 && parse->input[i - 1] != 92)
		parse->back_slash = true;
	if (parse->input[i] == 34 && !parse->back_slash)
		parse->double_quotes = !parse->double_quotes;
	if (parse->input[i] == 39 && !parse->back_slash)
		parse->single_quotes = !parse->single_quotes;
	if (parse->double_quotes)
		parse->extend = true;
	if (parse->single_quotes && !parse->double_quotes)
		parse->extend = false;
}

void	init_parse(char *input, t_parse *parse)
{
	parse->input = ft_malloc(ft_strlen(input) + 1);
	ft_strcpy(parse->input, input);
	parse->out = ft_malloc(ft_strlen(input) + 1);
	parse->extend = true;
	parse->double_quotes = false;
	parse->single_quotes = false;
}

/**
 *
 * @param c char to check
 * @return
 * @brief check if c is a valid env var name terminator
 */
bool	var_end_name(char c)
{
	if ((c >= 32 && c <= 39) || (c >= 42 && c <= 47) || c == 58 || c == 61
		|| c == 63 || c == 64 || c == 92 || c == 126)
		return (true);
	return (false);
}

/**
 * @brief get the name of a variable from the input string
 */
void	get_var_name(t_parse *parse, char *buf, int offset)
{
	int	i;

	i = 0;
	while (parse->input[offset] && !var_end_name(parse->input[offset]))
	{
		buf[i] = parse->input[offset];
		offset++;
		i++;
	}
	buf[i] = 0;
}
