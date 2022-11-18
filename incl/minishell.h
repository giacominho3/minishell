/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:53:13 by tterribi          #+#    #+#             */
/*   Updated: 2022/11/03 03:50:47 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <curses.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "signal.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include "../src/signals/incl/signals.h"
# include "../src/env/incl/env.h"
# include "../src/parsing/tokenizer/incl/tokens.h"
# include "../src/commands/incl/commands.h"
# include "../src/parsing//incl/parse.h"

extern   void   rl_replace_line(const char *text, int clear_undo);

typedef struct s_main
{
	char 			*cmd_line;
	struct s_env	*env_head;
	struct s_cmd	*cmd_head;
	short			main_exit_status;
} t_main;

/***********************************0*
*			errors macros			*
*************************************/
# define SYNTAX_ERR_DQUOT "Minishell: syntax error: double quotes opened but not closed\n"
# define SYNTAX_ERR_SQUOT "Minishell: syntax error: single quotes opened but not closed\n"
# define SYNTAX_ERR_INVALID_CHAR "Minishell: syntax error: invalid character\n"
/************************************
*				syntax				*
*************************************/
int		syntax_wrapper(struct s_cmd **cmd_head);
int		syntax(char *str);
bool	is_valid_syntax(char *str);
int		open_quotes_syntax(char *str, char quote);

/************************************
*				utils				*
*************************************/
int		ft_mat_col(char *str);
int		ft_mat_row(char **matrix);

/************************************
*			string utils			*
*************************************/
int		ft_strcmp(char *s1, char *s2);
bool	is_in_strings(char c, char *str);
int		ft_strlen(const char *str);
bool	is_valid_char(char c);
void	ft_strcpy(char *dst, char *src);
int		skip_intial_spaces(char *str);
int		trim_spaces(char *str, int len);
void	ft_offset_copy(char *dst, char *src, int offset, int stop);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
bool	valid_var_name(char c);
bool	var_term(char c);

#endif
