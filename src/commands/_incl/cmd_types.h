/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:19:50 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/09 03:34:14 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_TYPES_H
# define CMD_TYPES_H

struct	s_main;

typedef struct s_cmd
{
	char			*cmd;
	char			**execve_args;
	t_token_list	*tok_head;
	struct s_main	*main_ref;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

#endif
