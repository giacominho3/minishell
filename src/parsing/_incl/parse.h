/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 01:46:20 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 01:46:38 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "../../../incl/minishell.h"

typedef struct s_main	t_main;

typedef struct s_parse
{
	int		out_len;
	bool	extend;
	bool	single_quotes;
	bool	double_quotes;
	bool	back_slash;
	char	*out;
	char	*input;
}	t_parse;

bool	var_end_name(char c);
int		parse(t_token_list **tok_head, t_main *main);
int		parsing(t_main *main);
int		_parse(char *str, t_token_list *curr_tok, t_main *main);
int		logic_skip(char *str, int index);
bool	sep_conditions(char *str, int index);
void	init_parse(char *input, t_parse *parse);
int		var_name_len(char *string, int offset);
int		get_content_len(t_parse *parse, struct s_env **head, int offset);
void	expand_check(t_parse *parse, int i);
int		extended_len(t_parse *parse, t_env **head);
void	quotes_handler(t_parse *parse);
void	get_var_name(t_parse *parse, char *buf, int offset);
void	new_cmd_line(t_token_list *token, t_parse *parse);

#endif
