/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:51:40 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/26 08:06:44 by tterribi         ###   ########.fr       */
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

char	*parse(char *str)
{
	int		i;
	int		j;
	char	*ret;
	bool	expand;

	i = 0;
	j = 0;
	expand = true;
	// printf("len_final: %d\n", len_final(str));
	ret = malloc(sizeof(char *) * len_final(str));
	while (str[i])
	{
		if (str[i] == '\'')
			expand = expand_manager(expand);
		if (str[i] == '$' && expand)
		{
			j += expand_var(str, ret, i, j);
			continue ;
		}
		ret[j] = str[i];
		j++;
		i++;
	}
	return (ret);
}

// int	main(void)
// {
// 	parse("$USER $TERM_PROGRAM_VERSION");
// 	printf("tterrribbbili gay");
// }
