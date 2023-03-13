/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:51:40 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 01:26:45 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	_expand(t_parse *parse, int out_offset, int in_offset, t_env **head)
{
	char	*name;
	char	*content;
	int		i;

	name = ft_malloc(var_name_len(parse->input, out_offset + 1) + 1);
	content = ft_malloc(get_content_len(parse, head, in_offset + 1));
	get_var_name(parse, name, in_offset + 1);
	content = get_content_by_name(head, name);
	i = 0;
	while (content[i])
	{
		parse->out[out_offset] = content[i];
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
	int	j;

	i = 0;
	j = 0;
	while (parse->input[i])
	{
		expand_check(parse, i);
		if (parse->input[i] == 36 && parse->extend
			&& valid_var_name(parse->input[i + 1]))
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

int	_parse(char *cmd_line, t_token_list *curr_tok, t_main *main)
{
	t_parse	parse;

	init_parse(cmd_line, &parse);
	parse.out_len = extended_len(&parse, &main->env_head);
	parse.out = ft_malloc(parse.out_len + 1);
	if (!parse.out)
	{
		printf("error while allocating parse.out\n");
		return (1);
	}
	parse.double_quotes = false;
	parse.single_quotes = false;
	parse.extend = true;
	expand(&parse, &main->env_head);
	quotes_handler(&parse);
	new_cmd_line(curr_tok, &parse);
	return (0);
}

int	parse(t_token_list **tok_head, t_main *main)
{
	t_token_list	*curr;

	curr = (*tok_head);
	while (curr != NULL)
	{
		if (curr->type != TOK_HEREDOC)
			_parse(curr->token, curr, main);
		curr = curr->next;
	}
	return (0);
}

int	parsing(t_main *main)
{
	t_cmd	*curr;

	curr = main->cmd_head;
	while (curr != NULL)
	{
		parse(&curr->tok_head, main);
		curr = curr->next;
	}
	return (0);
}
