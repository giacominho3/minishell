/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:57:36 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 18:52:14 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "../../../incl/minishell.h"

/**
 * export
 */
int		export_printing(t_cmd *cmd);
void	copy_env_to_export(t_export **head, char **envp);
void	add_env_and_export(t_export *export, t_env *env);
int		builtin_export(t_cmd *cmd);
int		add_export_element(t_cmd *cmd);
void	print_export(t_cmd *cmd);
void	add_elements_to_export(t_cmd *cmd);
void	clear_export(t_export **head);
void	ft_add_export(t_export **head, char *str);
void	ft_set_export_data(t_export *node, char *str);
int		check_if_valid(char *arg);

/**
 * pwd
 */
int		builtin_pwd(t_cmd *cmd);

/**
 * cd
 */
int		builtin_cd(t_cmd *cmd);

/**
 * echo
 */
int		builtin_echo(t_cmd *cmd);
/**
 * env
 */
int		builtin_env(t_cmd *cmd);
/**
 * unset
 */
void	unset(t_cmd *cmd);
/**
 * exit
 */
void	builtin_exit(t_cmd *cmd);

#endif
