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

bool	var_name(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && <= 122) || )
}

int	ft_var_len(char const *string, int offset)
{
	int i;

	i = offset;
	if ()
	while (string[i])
	{

	}
}

int	ft_extended_len(char *string, struct s_env **head)
{
	int				i;
	int				var_len;
	char			*var_name;
	struct s_env	*curr;


	curr = (*head);
	while (string[i])
	{
		if (string[i] == 36 && is_valid_var_name(string[i]))
		{
			var_len = ft_var_len(string, i);
			var_name = (char *)malloc(var_len + 1);
		}
	}
}

void	ft_extend(char *extended_string, char *input, int i, struct s_env **head)
{
	char			*tmp;
	struct s_env	*curr;

	curr = (*head);
	extended_string = (char *)malloc(ft_extended_len(input, head) + 1);


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
	ft_expand(input, main->env_head);
}

// int	main(void)
// {
// 	parse("$USER $TERM_PROGRAM_VERSION");
// 	printf("tterrribbbili gay");
// }
