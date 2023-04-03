/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:26:02 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/09 03:26:03 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_TYPES_H
# define MAIN_TYPES_H

typedef struct s_main
{
	char		*cmd_line;
	char		**env_mat;
	t_env		*env_head;
	t_cmd		*cmd_head;
	t_export	*export_head;
	int			exit_status;
}	t_main;

#endif
