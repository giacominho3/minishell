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
# include "../src/parsing/tokenizer/incl/tokens.h"
# include "../src/commands/incl/commands.h"

/*
 *
 *
 *
 *
 * */

struct	s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
	struct s_env	*prev;
};

typedef struct s_main
{
	struct s_env	*env_head;
	struct s_cmd	*cmd_head;
	short			main_exit_status;
} t_main;

/***********************************0*
*			errors macros			*
*************************************/
//macros placeholder

/************************************
*				syntax				*
*************************************/
int		syntax(char *str);
bool	is_valid_syntax(char *str);
int		open_char_syntax(char *str, char open, char close);


/************************************
*				ENV_lists				*
*************************************/
void	ft_add_front(struct s_env **head, char *str);
void	ft_add_last(struct s_env **head, char *str);
void	ft_add_after(struct s_env *prev_node, char *str);
void	ft_add_before(struct s_env *next_node, char *str);
void	print_env(struct s_env **head);
void	ft_set_data(struct s_env *node, char *str);
void	copy_env(struct s_env **head, char **envp);
char	*get_content_by_name(struct s_env **head, char *name);

/************************************
*				parse				*
*************************************/
void	parse(char *str, t_main *main);
int		len_final(char *str);
int		len_var(char *str, int index);
//bool	expand_manager(bool expand);
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
bool	is_valid_var_name(char c);
bool	var_term(char c);

#endif