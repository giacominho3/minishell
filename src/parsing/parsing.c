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
			continue ;
		}
		dst[j] = src[i];
		j++;
		i++;
	}
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

void	expand_check(t_parse *parse, int i)
{
	if (parse->input[i] == 34)
		parse->double_quotes = !parse->double_quotes;
	if (parse->input[i] == 39 && parse->input[i - 1] != 92)
		parse->single_quotes = !parse->single_quotes;
	if (parse->double_quotes)
		parse->extend = true;
	if (parse->single_quotes && !parse->double_quotes)
		parse->extend = false;
}

int var_name_len(t_parse *parse, int offset)
{
	int	to_skip;

	to_skip = 0;
	while(parse->input[offset] && var_end_name(parse->input[offset]))
	{
		to_skip++;
		offset++;
	}
	return (to_skip);
}

void	var_content_cpy(char *dst, char *var_name, struct s_env **env)
{
	int		i;
	char	*tmp;

	i = 0;
	dst = malloc(ft_strlen(get_content_by_name(env, var_name)));
	if (!dst)
		return ;
	tmp = get_content_by_name(env, var_name);
	while (*tmp)
	{
		dst[i] = *tmp;
		i++;
		tmp++;
	}
}

int ft_extend(t_parse *parse, struct s_env **env, int offset)
{
	char	*var_name;
	char	*to_insert;
	int		i;
	int		j;

	i = 0;
	j = offset;
	var_name = malloc(var_name_len(parse, offset) + 1);
	while (parse->input[j] && var_end_name(parse->input[j]))
		var_name[i++] = parse->input[j++];
	var_name[i] = 0;
	printf("var_name: %s\n", var_name); //debug print
	var_content_cpy(to_insert, var_name, env);
	printf("to_insert: %s\n", to_insert); //debug print
	free(var_name);
	parse->out = malloc(ft_strlen(parse->out) - ft_strlen(var_name) + ft_strlen(to_insert));

}


/**
 *
 * @param input = string read by readline
 * @param struct s_env **head = head to the env list
 *
 * @brief whenever a var is found in the string and it can be expanded (following the bash standard)
 * this function (calling some other helper functions) replace the name of that variable with his
 * value (stored in the env).
 * */
int	ft_expand(t_parse *parse, struct s_env **head)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("PARSING\n");
	printf("parse input val: %s\n", parse->input);
//	while (parse->input[i])
//	{
//		expand_check(parse, i);
//		if (parse->input[i] == 36 && parse->extend
//			&& is_valid_var_name(parse->input[i+1]))
//		{
//			i += var_name_len(parse, i);
//			j += ft_extend(parse, head, i);
//		}
//		i++;
//	}
	printf("IGNORE: %s\n", (*head)->content);
	return (0);
}

int	parse(char *input, t_main *main)
{
	t_parse	parse;

	init_parse(input, &parse);
	ft_strcpy(parse.input, input);
	if (ft_expand(&parse, &main->env_head))
		return (1);
	return (0);
	//ft_expand(input, main->env_head);
}

