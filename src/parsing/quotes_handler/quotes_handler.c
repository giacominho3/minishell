/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 01:31:05 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 19:41:50 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/parse.h"

void	quotes_check(t_parse *parse, int i)
{
	if (parse->back_slash)
		parse->back_slash = false;
	if (parse->input[i] == 92 && parse->input[i - 1] != 92)
		parse->back_slash = true;
	if (parse->input[i] == 39 && !parse->back_slash)
		parse->double_quotes = !parse->double_quotes;
	if (parse->input[i] == 34 && !parse->back_slash)
		parse->single_quotes = !parse->single_quotes;
	if (parse->double_quotes)
		parse->extend = true;
	if (parse->single_quotes && !parse->double_quotes)
		parse->extend = false;
}

int	count_quotes_to_remove(t_parse *parse)
{
	int		i;
	int		cont;

	cont = 0;
	i = 0;
	while (parse->out[i])
	{
		quotes_check(parse, i);
		if (((parse->out[i] == 34 && !parse->double_quotes)
				|| (parse->out[i] == 39 && !parse->single_quotes))
			&& !parse->back_slash)
		{
			i++;
			cont++;
			continue ;
		}
		i++;
	}
	return (cont);
}

void	remove_quotes(char *modified, t_parse *parse)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (parse->out[i])
	{
		quotes_check(parse, i);
		if (parse->back_slash)
			i++;
		if (((parse->out[i] == 34 && !parse->double_quotes)
				|| (parse->out[i] == 39 && !parse->single_quotes))
			&& !parse->back_slash)
		{
			i++;
			continue ;
		}
		modified[j] = parse->out[i];
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
	parse->back_slash = false;
	cont = count_quotes_to_remove(parse);
	buf = ft_malloc((ft_strlen(parse->out) - cont) + 1);
	ft_strcpy(buf, parse->out);
	parse->single_quotes = false;
	parse->double_quotes = false;
	parse->back_slash = false;
	remove_quotes(buf, parse);
	ft_free(parse->out);
	parse->out = ft_malloc(ft_strlen(buf) + 1);
	i = -1;
	while (buf[++i])
		parse->out[i] = buf[i];
	parse->out[i] = 0;
}
