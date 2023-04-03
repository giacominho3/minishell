/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:53:01 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/09 03:53:03 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H
# include "../../../incl/minishell.h"

struct	s_main;

void	add_cmd_last(t_cmd **head, t_main *main, char *cmd);
int		command_splitter(char *input, struct s_main *main);
void	ft_cmdcpy(char *dest, const char *src, int len, int offset);
bool	cmd_split(const char *str, int index);
int		cmd_len(char *input, int offset);
void	clear_cmd_list(struct s_cmd **head);
int		cont_cmd_number(t_cmd **cmd_head);

//debug
void	print_cmd(struct s_cmd **head);

#endif
