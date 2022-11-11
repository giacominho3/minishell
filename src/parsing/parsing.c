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
			continue;
		}
		dst[j] = src[i];
		j++;
		i++;
	}
}

bool	sep_conditions(char *str, int index) {
	if (str[index] == '|')
		return (true);
	if (str[index] == '|' && str[index + 1] == '|')
		return (true);
	if (str[index] == '&' && str[index + 1] == '&')
		return (true);
	if (str[index] == '(')
		return (true);
	if (str[index] == '[')
		return (true);
	if (str[index] == '{')
		return (true);
	if (str[index] == ';')
		return (true);
	return (false);
}

int	logic_skip(char *str, int index)
{
	if (str[index] == '|' && str[index + 1] == '|')
		return (2);
	if (str[index] == '|')
		return (1);
	if (str[index] == '&' && str[index + 1] == '&')
		return (2);
	if (str[index] == '(')
		return (1);
	if (str[index] == '[')
		return (1);
	if (str[index] == '{')
		return (1);
	if (str[index] == ';')
		return (1);
	return (0);
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

//int	ft_var_len(char const *string, int offset)
//{
//	int i;
//
//	i = offset;
//	while (string[i])
//	{
//
//	}
//}


//		if (input[i] == 34)
//			double_quotes = !double_quotes;
//		if (input[i] == 39 && input[i - 1] != 92)
//			single_quotes = !single_quotes;
//		if (double_quotes)
//			extend = true;
//		if (single_quotes && !double_quotes)
//			extend = false;
//		if (input[i] == 36 && extend && is_valid_var_name(input[i+1]))

/**
 *
 * @param input = string read by readline
 * @param struct s_env **head = head to the env list
 *
 * @brief whenever a var is found in the string and it can be expanded (following the bash standard)
 * this function (calling some other helper functions) replace the name of that variable with his
 * value (stored in the env).
 * */
int	ft_expand(t_parse *birch, struct s_env **head)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("PARSING\n");
	printf("birch input val: %s\n", birch->input_string);
	while (birch->input_string[i])
	{
		if (birch->input_string[i] == 34)
			birch->double_quotes = !birch->double_quotes;
		if (birch->input_string[i] == 39 && birch->input_string[i - 1] != 92)
			birch->single_quotes = !birch->single_quotes;
		if (birch->double_quotes)
			birch->extend = true;
		if (birch->single_quotes && !birch->double_quotes)
			birch->extend = false;
		if (birch->input_string[i] == 36 && birch->extend
			&& is_valid_var_name(birch->input_string[i+1]))
	}
	printf("IGNORE: %s\n", (*head)->content);
	return (0);
}

void	init_birch(char *input, t_parse *birch)
{
	birch = malloc(sizeof(t_parse));
	birch->input_string = malloc(ft_strlen(input));
	if (!birch || !birch->input_string)
	{
		perror("error while allocating a stack of brich planks\n");
		return ;
	}
	birch->extend = true;
	birch->double_quotes = false;
	birch->single_quotes = false;
}

int	parse(char *input, t_main *main)
{
	t_parse	*birch_planks;

	init_birch(input, parse);
	ft_strcpy(birch_planks->input_string, input);
	if (ft_expand(birch_planks, main->env_head))
		return (1);
	return (0);
	//ft_expand(input, main->env_head);
}

