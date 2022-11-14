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
	if (parse->input[i] == 34 && parse->input[i - 1] != 92)
		parse->double_quotes = !parse->double_quotes;
	if (parse->input[i] == 39 && parse->input[i - 1] != 92)
		parse->single_quotes = !parse->single_quotes;
	if (parse->double_quotes)
		parse->extend = true;
	if (parse->single_quotes && !parse->double_quotes)
		parse->extend = false;
}

void	var_content_cpy(char **dst, char *var_name, struct s_env **env)
{
	int		i;
	char	*tmp;

	i = 0;
	*dst = malloc(ft_strlen(get_content_by_name(env, var_name)) + 1);
	if (!dst)
		return ;
	tmp = get_content_by_name(env, var_name);
	while (*tmp)
	{
		*dst[i] = *tmp;
		i++;
		tmp++;
	}
	*dst[i] = 0;
}
/*
int ft_extend(t_parse *parse, struct s_env **env, int offset)
{
	char	*var_name;
	char	*out;
	int		i;
	int		j;

	printf("------------working on------------\n");
	i = 0;
	j = offset;
	out = NULL;
	var_name = malloc(var_name_len(parse, offset) + 1);
	while (parse->input[j] && var_end_name(parse->input[j]))
		var_name[i++] = parse->input[j++];
	var_name[i] = 0;
	printf("var_name: %s\n", var_name); //debug print
	var_content_cpy(&out, var_name, env);
	printf("out: %s\n", out); //debug print
	printf("parse.out len: %s\n", parse->out);
	printf("var_name len: %s\n", var_name);
	printf("out len: %s\n", out);
	parse->out = malloc(ft_strlen(parse->out) - ft_strlen(var_name) + ft_strlen(out));
	printf("----------------------------------\n");
	free(var_name);
	return (0);
}
*/

/**
 *
 * @param input = string read by readline
 * @param struct s_env **head = head to the env list
 *
 * @brief whenever a var is found in the string and it can be expanded (following the bash standard)
 * this function (calling some other helper functions) replace the name of that variable with his
 * value (stored in the env).
 * */
/*
int	ft_expand(t_parse *parse, struct s_env **head)
{
	int	i; //input offset
	int	j; //output offset

	i = 0;
	j = 0;
	printf("PARSING\n");
	printf("parse input val: %s\n", parse->input);
	while (parse->input[i])
	{
		printf("squotes: %d\n", parse->single_quotes);
		printf("dquotes: %d\n", parse->double_quotes);
		printf("expand: %d\n", parse->extend);
		expand_check(parse, i);
		if (parse->input[i] == 36 && parse->extend
			&& is_valid_var_name(parse->input[i+1]))
		{
			i += var_name_len(parse, i);
			j += ft_extend(parse, head, i);
			continue ;
		}
		parse->out[j] = parse->input[i];
		i++;
		j++;
	}
	parse->out[j] = 0;
	printf("parse.out: %s\n", parse->out);
	printf("IGNORE: %s\n", (*head)->content);
	return (0);
}
*/
/**
 * @brief when found a var counts the length of it's name
 * (doesn't count the $)
 */
int	var_name_len(char *string, int offset)
{
	int	len;

	len = 0;
	while (string[offset] && !var_end_name(string[offset]))
	{
		offset++;
		len++;
	}
	return (len);
}


int get_content_len(t_parse *parse, struct s_env **head, int offset)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = offset;
	buf = malloc(var_name_len(parse->input, offset) + 1);
	if (!buf)
		return (0);
	while (parse->input[j] && !var_end_name(parse->input[j]))
		buf[i++] = parse->input[j++];
	buf[i] = 0;
	printf("buf: %s\n", buf);
	i = ft_strlen(get_content_by_name(head, buf));
	printf("get_content_by_name output: %s\n", get_content_by_name(head, buf));
	printf("get_content_len output: %d\n", i);
	free(buf);
	return (i);
}

int	extended_len(t_parse *parse, t_env **head)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (parse->input[i])
	{
		expand_check(parse, i);
		if (parse->input[i] == 36 && parse->extend
			&& is_valid_var_name(parse->input[i+1]))
		{
			len += get_content_len(parse, head, len + 1);
			printf("len: %d\n", len);
			i += var_name_len(parse->input, i + 1) + 1;
			printf("i: %d\n", i);
			continue ;
		}
		len++;
		i++;
	}
	return (len);
}

int	parse(char *input, t_main *main)
{
	t_parse	parse;

	init_parse(input, &parse);
	printf("extended len: %d\n", extended_len(&parse, &main->env_head));
	return 0;
//	parse.input = malloc(ft_strlen(input) + 1);
//	ft_strcpy(parse.input, input);
//	if (ft_expand(&parse, &main->env_head))
//		return (1);
//	return (0);
}

