/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:19:08 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/25 19:54:28 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/parse.h"

/**
 * @brief check if a variable have to be extended or considering quotes
 */
void	expand_check(t_parse *parse, int i)
{
	if (parse->input[i] == 34 && parse->input[i - 1] != 92)
		parse->double_quotes = !parse->double_quotes;
	if (parse->input[i] == 39 && parse->input[i - 1] != 92)
		parse->single_quotes = !parse->single_quotes;
	if (parse->double_quotes)
		parse->extend = true;
	if (parse->single_quotes && !parse->double_quotes)
		parse->extend = false;
}

void	init_parse(char *input, t_parse *parse)
{
	printf("parsing init started\n");
	parse->input = malloc(ft_strlen(input) + 1);
	ft_strcpy(parse->input, input);
	parse->out = malloc(ft_strlen(input) + 1);
	if (!parse->input || !parse->out)
	{
		printf("error while allocating your mom(too fat)\n");
		return ;
	}
	printf("input: %s\n", input);
	printf("parse.input: %s\n", parse->input);
	parse->extend = true;
	parse->double_quotes = false;
	parse->single_quotes = false;
	printf("parsing init terminated\n");
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

