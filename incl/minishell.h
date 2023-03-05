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
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
/**
 * structures includes
 * */
# include "../src/gc/_incl/AliMalloc.h"
# include "../src/env/_incl/env_types.h"
# include "../src/parsing/_incl/tok_types.h"
# include "../src/commands/_incl/cmd_types.h"
# include "../src/exec/_incl/export_types.h"
# include "main_types.h"
/**
 * other includes
 * */
# include "../src/exec/_incl/redirections.h"
# include "../libft/libft.h"
# include "../src/syntax/_incl/syntax.h"
# include "../src/env/_incl/env.h"
# include "../src/signals/incl/signals.h"
# include "../src/parsing/_incl/tokens.h"
# include "../src/commands/_incl/commands.h"
# include "../src/parsing/_incl/parse.h"
# include "../src/exec/_incl/heredoc.h"
# include "../src/exec/_incl/exec.h"
# include "../src/exec/_incl/pipeline.h"
# include "../src/exec/_incl/builtins.h"

t_AliMalloc	*AliMalloc;

extern void	rl_replace_line(const char *text, int clear_undo);

/********************************
*	string tokenization_utils	*
*********************************/
void	ft_exit(t_main *main);
int		ft_strcmp(char *s1, char *s2);
bool	is_in_strings(char c, char *str);
int		ft_strlen(const char *str);
bool	is_valid_char(char c);
void	ft_strcpy(char *dst, char *src);
int		skip_intial_spaces(char *str);
int		trim_spaces(char *str, int len);
void	ft_offset_copy(char *dst, char *src, int offset, int stop);
char	*ft_strdup(const char *src);
bool	valid_var_name(char c);
bool	var_term(char c);
char	*ft_strndup(char *s, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*trim_trailing_spaces(char *str);

//char	*ft_strjoin(char const *s1, char const *s2);

#endif
