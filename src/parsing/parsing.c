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

/**
 * @brief get the name of a variable from the input string
 */
void	get_var_name(t_parse *parse, char *buf, int offset)
{
	int	i;

	i = 0;
	while (parse->input[offset] && !var_end_name(parse->input[offset]))
	{
		buf[i] = parse->input[offset];
		offset++;
		i++;
	}
	buf[i] = 0;
}

int	_expand(t_parse *parse, int out_offset, int in_offset, t_env **head)
{
	char	*name;
	char	*content;
	int		i;

	name = malloc(var_name_len(parse->input, out_offset + 1) + 1);
	content = malloc(get_content_len(parse, head, in_offset + 1));
	get_var_name(parse, name, in_offset + 1);
	content = get_content_by_name(head, name);
	printf("CONTENT: %s\n", content); //debug print
	printf("NAME: %s\n", name); //debug print
	i = 0;
	while (content[i])
	{
		parse->out[out_offset] = content[i];
		printf("PARSE.OUT: %c\n", parse->out[out_offset]); //debug print
		printf("CONTENT: %c\n", content[i]); //debug print
		out_offset++;
		i++;
	}
	return (out_offset);
}

/**
 * @brief expand the variables that are found in the input (considering quotes)
 */
void	expand(t_parse *parse, t_env **head)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	printf("___expand___\n"); //debug print
	while (parse->input[i])
	{
		printf("reading char[%d]: %c\n", i, parse->input[i]); //debug print
		expand_check(parse, i);
		if (parse->input[i] == 36 && parse->extend
			&& valid_var_name(parse->input[i+1]))
		{
			j = _expand(parse, j, i, head);
			i += 1 + var_name_len(parse->input, i + 1);
			continue ;
		}
		parse->out[j] = parse->input[i];
		i++;
		j++;
	}
	parse->out[j] = 0;
}

int	parse(char *input, t_main *main)
{
	t_parse	parse;

	init_parse(input, &parse);
	parse.out_len = extended_len(&parse, &main->env_head);
	parse.out = malloc(parse.out_len + 1);
	if (!parse.out)
	{
		printf("error while allocating parse.out\n");
		return (1);
	}
	parse.double_quotes = false;
	parse.single_quotes = false;
	parse.extend = true;
	expand(&parse, &main->env_head);
	printf("extended len: %d\n", extended_len(&parse, &main->env_head)); //debug print
	printf("el stringo: |%s|\n", parse.out); //debug print
	printf("___quotes handler___\n"); //debug print
	quotes_handler(&parse);
	return (0);
}

