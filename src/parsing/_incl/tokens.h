/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 01:47:10 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/13 01:47:17 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H
# include "../../../incl/minishell.h"

int		tokenizer(t_cmd **cmd_head);
bool	invalid_pipe(char *cmd_line, int i);

/**
 * Scan functions
 */
int		head_scan(char *cmd, int i, t_token_list **tok_head);
int		body_scan(char *cmd, int i, t_token_list **tok_head);
int		tail_scan(char *cmd, int i, t_token_list **tok_head);

/**
 * Scan tokenization_utils functions
 */
int		scan_redirections(char *cmd, int i, t_token_list **tok_head);
char	*get_redir(char *cmd, int i);
int		calc_tok_len(char *cmd, int i);
bool	is_metacharacter(char c);
bool	is_skippable(char c);
int		skip_spaces(char *cmd, int i);
bool	not_operator(char c);
int		calc_arg_len(char *cmd, int i);
char	*get_heredoc(char *cmd, int i);

/**
 * List managing functions
 */
void	ft_add_tok_last(t_token_list **head, t_tokens type, char *tok_val);
void	clear_tokens(t_token_list **head);
void	print_token_lists(t_cmd **head);
int		cont_tok_by_type(t_token_list **head, t_tokens type);
int		token_list_len(t_token_list **tok_head);
char	*get_tok_content_by_type(t_token_list **head, t_tokens type);
void	print_toks(t_token_list **head);

/**
 * General tokenization_utils functions
 */
char	*ft_strndup(char *s, size_t n);
char	**ft_split_args(char *str);

#endif
