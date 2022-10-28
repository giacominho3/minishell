/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:51:40 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/28 18:45:23 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

bool	expand_manager(bool expand)
{
	if (expand)
		return (false);
	else
		return (true);
}

int	expand_var(char *str, char *ret, int offset, int index)
{
	char	*var;
	char	*tmp;
	int		i;
	int		j;

	printf("string in input: %s\n", str);
	i = 0;
	j = offset;
	printf("len var: %d", len_var(str, offset));
	tmp = (char *)malloc(sizeof(char) * len_var(str, offset));
	if (!tmp)
		return (-1);
	write(1, "a\n", 2);
	while (is_valid_char(str[offset]))
	{
		write(1, "a\n", 2);
		tmp[i++] = str[j++];
	}
	printf("tmp: %s\n", tmp);
	var = getenv(tmp);
	i = 0;
	while (var[i])
		ret[index++] = var[i++];
	return (len_var(str, offset));
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

void	invalid_command(char *str)
{
	/* take the param string and read and copy it until the first space (skipping single and double quotes)
	and then print an error message with the copied string (just like bash error: "command not found") */
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i] && str[i] != 32)
	{
		if (str[i] == 34 || str[i] == 39)
		{
			i++;
			continue ;
		}
		j++;
		i++;
	}
	tmp = (char *) malloc(j + 1);
	if (!tmp)
	{
		perror("parsing.c:69:71 | invalid_command()");
		return ;
	}
	error_command_cpy(tmp,str);
	printf("Minishell: %s: command not found\n", tmp);
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

void	parse(char *str)
{
	int		i;
	int		j;
	char	*ret;
	bool	expand;
	int cont;

	i = 0;
	j = 0;
	expand = true;

	if (syntax(str))
		return ;
	cont = cmd_count(str);
	cmds_node_create();
	printf("cont = %d\n", cont);
	return ;
}

// int	main(void)
// {
// 	parse("$USER $TERM_PROGRAM_VERSION");
// 	printf("tterrribbbili gay");
// }
