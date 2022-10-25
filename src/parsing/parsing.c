/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:51:40 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/25 08:44:34 by tterribi         ###   ########.fr       */
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
	while ((str[index] >= 65 && str[index] <= 90) || (str[index] >= 97 && str[index] <= 122))
		tmp[len++] = str[index++];
	var_pointer = getenv(tmp);
	// add error handling for get env
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
	while (str[i])
	{
		if (str[i] == '\'')
			expand = expand_manager(expand);
		if (str[i] == '$' && expand)
			len += len_var(str, i + 1);
		i++;
	}
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
