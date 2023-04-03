/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:59:09 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/09 14:46:55 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/exec.h"

char	*find_cmd_path(t_cmd *cmd)
{
	char	**path_matrix;
	char	*path;
	int		i;

	if (!access(get_tok_content_by_type(&cmd->tok_head, TOK_CMD), F_OK))
		return (get_tok_content_by_type(&cmd->tok_head, TOK_CMD));
	i = 0;
	path_matrix = ft_split(
			get_content_by_name(&cmd->main_ref->env_head, "PATH"), ':');
	while (path_matrix[i])
	{
		path = complete_path(path_matrix[i], cmd);
		if (!access(path, F_OK))
		{
			ft_free_matrix(path_matrix);
			return (path);
		}
		ft_free(path);
		i++;
	}
	ft_free_matrix(path_matrix);
	return (NULL);
}

int	exe_builtins(t_cmd *cmd)
{
	char	*tmp;

	tmp = ft_malloc(
			ft_strlen(get_tok_content_by_type(&cmd->tok_head, TOK_CMD)) + 1);
	if (!tmp)
		return (1);
	ft_strcpy(tmp, get_tok_content_by_type(&cmd->tok_head, TOK_CMD));
	if (!ft_strcmp("echo", tmp))
		return (builtin_echo(cmd));
	if (!ft_strcmp("pwd", tmp))
	{
		builtin_pwd(cmd);
		return (0);
	}
	if (!ft_strcmp("export", tmp) && (token_list_len(&cmd->tok_head) == 1))
		return (export_printing(cmd));
	if (!ft_strcmp("env", tmp))
		return (builtin_env(cmd));
	ft_free(tmp);
	return (1);
}

void	print_mat(char **mat)
{
	int	i;

	i = 0;
	if (mat[i] == NULL)
		printf("dioghane\n");
	while (mat[i])
	{
		printf("%d -> |%s|\n", i, mat[i]);
		i++;
	}
}

int	execute(t_cmd *cmd)
{
	char	*path;

	if (exe_builtins(cmd))
	{
		path = find_cmd_path(cmd);
		args_format(cmd, path);
		if (execve(path, cmd->execve_args, cmd->main_ref->env_mat) == -1)
		{
			perror("Minishell");
			exit (EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}
