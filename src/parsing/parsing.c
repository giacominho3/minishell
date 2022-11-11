/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:51:40 by tterribi          #+#    #+#             */
/*   Updated: 2022/11/03 03:57:26 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	error_command_cpy(char *dst, char *src)
{
	// utils func for invalid command
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i] != 32 && src[i])
	{
		if (src[i] == 34 || src[i] == 39)
		{
			i++;
			continue ;
		}
		dst[j] = src[i];
		j++;
		i++;
	}
}

int	cmd_count( char *str)
{
	int	i;
	int	cont;

	i = 0;
	cont = 1;
	while(str[i])
	{
		if (sep_conditions(str, i))
		{
			i += logic_skip(str, i);
			cont++;
			continue ;
		}
		i++;
	}
	return (cont);
}


void	expand_check(t_parse *parse, int i)
{
	if (parse->input_string[i] == 34)
		parse->double_quotes = !parse->double_quotes;
	if (parse->input_string[i] == 39 && parse->input_string[i - 1] != 92)
		parse->single_quotes = !parse->single_quotes;
	if (parse->double_quotes)
		parse->extend = true;
	if (parse->single_quotes && !parse->double_quotes)
		parse->extend = false;
}
//
//int	ft_chain_join(t_parse *parse)
//{
//
//}

/**
 *
 * @param input = string read by readline
 * @param struct s_env **head = head to the env list
 *
 * @brief whenever a var is found in the string and it can be expanded (following the bash standard)
 * this function (calling some other helper functions) replace the name of that variable with his
 * value (stored in the env).
 * */
int	ft_expand(t_parse *parse, struct s_env **head)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("PARSING\n");
	printf("parse input val: %s\n", parse->input_string);
	while (parse->input_string[i])
	{
		expand_check(parse, i);
//		if (parse->input_string[i] == 36 && parse->extend
//			&& is_valid_var_name(parse->input_string[i+1]))
//		{
//			i += ft_chain_join(parse);
//		}
	}
	printf("IGNORE: %s\n", (*head)->content);
	return (0);
}

int	parse(char *input, t_main *main)
{
	t_parse	parse;

	init_parse(input, &parse);
	ft_strcpy(parse.input_string, input);
	if (ft_expand(&parse, &main->env_head))
		return (1);
	return (0);
	//ft_expand(input, main->env_head);
}

