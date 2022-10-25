/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:51:40 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/25 19:51:59 by tterribi         ###   ########.fr       */
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

	i = 0;
	j = offset;
	tmp = (char *)malloc(sizeof(char) * len_var(str, offset));
	if (!tmp)
		return (-1);
	while (is_valid_char(str[offset]))
		tmp[i++] = str[j++];
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
	printf("len_final: %d", len_final(str));
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
