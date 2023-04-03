/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 01:20:28 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/13 01:21:43 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H
# include "../../../incl/minishell.h"

# define SYNTAX_ERR_DQUOT "Minishell: syntax: d. quotes opened but not closed\n"
# define SYNTAX_ERR_SQUOT "Minishell: syntax: s. quotes opened but not closed\n"
# define SYNTAX_ERR_INVALID_CHAR "Minishell: syntax: invalid character\n"
# define SYNTAX_ERR_REDIR "Minishell: syntax: invalid redirection token\n"
# define SYNTAX_ERR_PIPE "Minishell: syntax: invalid pipe symbol\n"

int		syntax_wrapper(struct s_cmd **cmd_head);
int		syntax(char *str);
bool	is_valid_syntax(char *str);
int		open_quotes_syntax(char *str, char quote);
int		open_char_syntax(char *string, char open, char close);
int		pipe_appended(char *string, char pipe);
int		ft_isprint(int arg);
int		pipe_syntax(char *str);

#endif
