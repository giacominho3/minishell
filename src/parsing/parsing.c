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



/**
 *
 * @param ext_string = final string
 * @param input = string read by readline
 * @param i = index where there's a var inside @param input
 * @param head = head to env list
 *
 * @brief replace the name of a env's var with his value
 */

/**
 *
 * @param input = string read by readline
 * @param struct s_env **head = head to the env list
 *
 * @brief whenever a var is found in the string and it can be expanded (following the bash standard)
 * this function (calling some other helper functions) replace the name of that variable with his
 * value (stored in the env).
 * */
void	ft_expand(char *input, struct s_env **head)
{
	int		i;
	bool	single_quotes;
	bool	double_quotes;
	bool	extend;
	char	*extended_string;

	single_quotes = false;
	double_quotes = false;
	extend = true;
//	extended_string = (char *) malloc(ft_extended_len(input, head));
	return ;
	while (input[i])
	{
		if (input[i] == 34)
			double_quotes = !double_quotes;
		if (input[i] == 39 && input[i - 1] != 92 && !single_quotes)
			single_quotes = !single_quotes;
		if (double_quotes)
			extend = true;
		if (single_quotes && !double_quotes)
			extend = false;
		if (input[i] == 36 && extend && is_valid_var_name(input[i]))
		i++;
	}
}

void	parse(char *input, t_main *main)
{
//	syntax(input);
	ft_expand(input, &main->env_head);
	if (ft_strcmp(input, "env") == 0)
		print_env(&main->env_head);
	//ft_expand(input, main->env_head);
}

