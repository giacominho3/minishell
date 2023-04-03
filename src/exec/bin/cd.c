/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 04:07:22 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/12 04:53:36 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/builtins.h"

int	builtin_cd(t_cmd *cmd)
{
	char	buf[PATH_MAX];
	char	*dest;
	char	*old_pwd;

	dest = get_tok_content_by_type(&cmd->tok_head, TOK_ARGS);
	old_pwd = get_content_by_name(&cmd->main_ref->env_head, "PWD");
	if (chdir(dest) == -1)
	{
		perror("minishell:");
		return (cmd->main_ref->exit_status = 1);
	}
	getcwd(buf, PATH_MAX);
	if (modify_node_content(&cmd->main_ref->env_head, "PWD", buf))
	{
		printf("minishell: cd: error while updating the PWD\n");
		return (cmd->main_ref->exit_status = 2);
	}
	if (modify_node_content(&cmd->main_ref->env_head, "OLDPWD", old_pwd))
	{
		printf("minishell: cd: error while updating the OLDPWD\n");
		return (cmd->main_ref->exit_status = 3);
	}
	return (0);
}
