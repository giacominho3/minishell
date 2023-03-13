/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:58:03 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/09 03:58:10 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "../../../incl/minishell.h"

# define READ 0
# define WRITE 1

/**
 * Access
 */
int		execute(t_cmd *cmd);

/**
 * Access utils
 */
char	*find_cmd_path(t_cmd *cmd);
char	*complete_path(char *src, t_cmd *cmd);
void	ft_free_matrix(char **matrix);
char	*complete_path(char *src, t_cmd *cmd);
void	args_format(t_cmd *cmd, char *path);
int		exe_builtins(t_cmd *cmd);

#endif //MINISHELL_EXEC_H
