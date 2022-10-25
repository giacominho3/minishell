/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:51:40 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/25 08:26:43 by tterribi         ###   ########.fr       */
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

int	len_var(char *str, int index)
{
	int		len;
	char	tmp[200];
	char	*var_pointer;

	len = 0;
	tmp[0] = 0;
	write (1, "1\n", 2);
	printf("len: %lu", strlen(str));
	sleep(2);
	while (str[index] != 0 || str[index] != 32)
	{
		write(1, &str[index], 1);
		index++;
	}
	write (1, "2\n", 2);
	var_pointer = getenv(tmp);
	write (1, "3\n", 2);
	len = 0;
	while (var_pointer[len])
		len++;
	return (len);
}

int	len_final(char *str)
{
	int		i;
	int		len;
	bool	expand;

	expand = true;
	i = 0;
	len = 0;
	write (1, "a\n", 2);
	while (str[i])
	{
		write (1, "c\n", 2);
		if (str[i] == '\'')
			expand = expand_manager(expand);
		write (1, "d\n", 2);
		if (str[i] == '$' && expand)
			len += len_var(str, i + 1);
		write (1, "e\n", 2);
		i++;
	}
	write (1, "b\n", 2);
	return (len);
}

// void	*expand_var(char *str)
// {

// }

char	*parse(char *str)
{
	int		i;
	char	*ret;
	bool	expand;

	i = 0;
	expand = true;
	printf("len_final: %d", len_final(str));
	exit(0);
	ret = malloc(sizeof(char *) * len_final(str));
	while (str[i])
	{
		if (str[i] == '\'')
			expand = expand_manager(expand);
		if (str[i] == '$' && expand)
			// expand_var(str);

		i++;
	}
}

int	main (void)
{
	parse("$USER");
}
