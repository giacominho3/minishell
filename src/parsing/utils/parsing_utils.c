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

//bool	sep_conditions(char *str, int index) {
//	if (str[index] == '|')
//		return (true);
//	if (str[index] == '|' && str[index + 1] == '|')
//		return (true);
//	if (str[index] == '&' && str[index + 1] == '&')
//		return (true);
//	if (str[index] == '(')
//		return (true);
//	if (str[index] == '[')
//		return (true);
//	if (str[index] == '{')
//		return (true);
//	if (str[index] == ';')
//		return (true);
//	return (false);
//}
//
//int	logic_skip(char *str, int index)
//{
//	if (str[index] == '|' && str[index + 1] == '|')
//		return (2);
//	if (str[index] == '|')
//		return (1);
//	if (str[index] == '&' && str[index + 1] == '&')
//		return (2);
//	if (str[index] == '(')
//		return (1);
//	if (str[index] == '[')
//		return (1);
//	if (str[index] == '{')
//		return (1);
//	if (str[index] == ';')
//		return (1);
//	return (0);
//}

bool	sep_conditions(char *str, int index)
{
	if (str[index] == '|' && str[index + 1] == '|')
		return (true);
	if (str[index] == '&' && str[index + 1] == '&')
		return (true);
	if (str[index] == '|')
		return (true);
	return (false);
}

int	logic_skip(char *str, int index)
{
	if (str[index] == '|' && str[index + 1] == '|')
		return (2);
	if (str[index] == '&' && str[index + 1] == '&')
		return (2);
	if (str[index] == '|')
		return (1);
	return (0);
}

void	init_parse(char *input, t_parse *parse)
{
	parse = malloc(sizeof(t_parse));
	parse->input_string = malloc(ft_strlen(input));
	if (!parse->input_string)
	{
		perror("error while allocating a stack of brich planks\n");
		return ;
	}
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

