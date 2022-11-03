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

int	expand_var(char *str, char *ret, int offset, int index)
{

}

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

void	ft_extend(char *extended_string, char *input, int i, struct s_env **head)
{
	char			*tmp;
	struct s_env	*curr;

	curr = (*head);



}


/**
 *
 * @param input = string read by readline
 *
 *
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
	while (input[i])
	{
		if (input[i] == 34)
			double_quotes = !double_quotes;
		if (input[i] == 39 && input[i - 1] != 92)
			single_quotes = !single_quotes;
		if (double_quotes)
			extend = true;
		if (single_quotes && !double_quotes)
			extend = false;
		if (input[i] == 36 && extend)
			ft_extend(extended_string, input, i, head);
	}

}

void	parse(char *input, t_main *main)
{
	ft_expand();
}

// int	main(void)
// {
// 	parse("$USER $TERM_PROGRAM_VERSION");
// 	printf("tterrribbbili gay");
// }
