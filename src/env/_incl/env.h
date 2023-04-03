/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:55:59 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/09 03:56:33 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "../../../incl/minishell.h"

/**
 * add functions
 */
void	ft_add_front(struct s_env **head, char *str);
void	ft_add_last(struct s_env **head, char *str);
void	ft_add_after(struct s_env *prev_node, char *str);
void	ft_add_before(struct s_env *next_node, char *str);
void	free_env_node(t_env *node);

/**
 * general functions
 */
void	print_env(struct s_env **head);
void	copy_env(struct s_env **head, char **envp);
void	clear_env(struct s_env **head);

/**
 * tokenization_utils functions
 */
bool	find_char_instr(char c, char *str);
void	ft_set_data(struct s_env *node, char *str);
char	*get_content_by_name(struct s_env **head, char *name);
char	*ft_get_content(char *str, char c);
char	*ft_get_name(char *str, char c);
int		modify_node_content(t_env **head, char *node_name, char *new_content);

#endif
