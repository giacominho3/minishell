/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 01:31:05 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 01:45:52 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/parse.h"

int	count_quotes_to_remove(char *string)
{
	int		i;
	int		cont;
	bool	keep_single;
	bool	keep_double;

	i = 0;
	cont = 0;
	keep_double = false;
	keep_single = false;
	while (string[i])
	{
		if (string[i] == 39 && !keep_single)
			keep_double = !keep_double;
		if (string[i] == 34 && !keep_double)
			keep_single = !keep_single;
		if ((string[i] == 34 && !keep_double)
			|| (string[i] == 39 && !keep_single))
		{
			i++;
			cont++;
			continue ;
		}
		i++;
	}
	return (cont);
}

void	remove_quotes(char *modified, char *original)
{
	int		i;
	int		j;
	bool	singleq;
	bool	doubleq;

	i = 0;
	j = 0;
	doubleq = false;
	singleq = false;
	while (original[i])
	{
		if (original[i] == 39 && !singleq)
			doubleq = !doubleq;
		if (original[i] == 34 && !doubleq)
			singleq = !singleq;
		if ((original[i] == 34 && !doubleq) || (original[i] == 39 && !singleq))
		{
			i++;
			continue ;
		}
		modified[j] = original[i];
		i++;
		j++;
	}
	modified[j] = 0;
}

void	quotes_handler(t_parse *parse)
{
	int		i;
	int		cont;
	char	*buf;

	parse->single_quotes = false;
	parse->double_quotes = false;
	cont = count_quotes_to_remove(parse->out);
	buf = ft_malloc((ft_strlen(parse->out) - cont) + 1);
	ft_strcpy(buf, parse->out);
	remove_quotes(buf, parse->out);
	ft_free(parse->out);
	parse->out = ft_malloc(ft_strlen(buf) + 1);
	i = -1;
	while (buf[++i])
		parse->out[i] = buf[i];
	parse->out[i] = 0;
}
