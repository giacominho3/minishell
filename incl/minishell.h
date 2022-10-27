/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:53:13 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/27 12:36:54 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <curses.h>
# include <dirent.h>
# include <readline/readline.h>
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

typedef struct s_command
{
	char	**commands;
	int		mat_y;
	int		mat_x;
}	t_command;

typedef struct s_shell
{
	char	**env;
}	t_shell;

struct	s_env
{
	char			*name;
	char			*content;
	int				val;
	struct s_env	*next;
	struct s_env	*prev;
};

/************************************
*			errors macros			*
*************************************/
//macros placeholder

/************************************
*				syntax				*
*************************************/
int		*syntax(char *str);

/************************************
*				ENV_lists				*
*************************************/
void	ft_add_front(struct s_env **head, char *str);
void	ft_add_last(struct s_env **head, char *str);
void	ft_add_after(struct s_env *prev_node, char *str);
void	ft_add_before(struct s_env *next_node, char *str);
void	print_list(struct s_env **head);
void	ft_set_data(struct s_env *node, char *str);
void	copy_env(struct s_env **head, char **envp);
/************************************
*				parse				*
*************************************/
char	*parse(char *str);
int		len_final(char *str);
int		len_var(char *str, int index);
bool	expand_manager(bool expand);
void	matrix_alloc_wrapper(char *str, t_command *cmds);
int		logic_skip(char *str, int index);
bool	sep_conditions(char *str, int index);

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

#endif