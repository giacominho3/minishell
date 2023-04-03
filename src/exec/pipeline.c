/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 05:15:41 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/13 17:28:43 by gifulvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_incl/pipeline.h"

int	gen_last_process(t_cmd *cmd, pid_t pid, int *tmp)
{
	pid = fork();
	if (pid < 0)
		return (2);
	if (pid == 0)
	{
		if (cont_tok_by_type(&cmd->tok_head, TOK_REDIRECTION))
			redirections(cmd, NULL, tmp, 0);
		else
		{
			dup2(*tmp, STDIN_FILENO);
			close(*tmp);
		}
		execute(cmd);
	}
	else
	{
		while (waitpid(-1, &cmd->main_ref->exit_status, 0) != -1)
			;
		close(*tmp);
		*tmp = dup(0);
	}
	return (0);
}

int	gen_std_process(t_cmd *cmd, int fd[], pid_t pid, int *tmp)
{
	if (pipe(fd) < 0)
		return (2);
	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
	{
		if (cont_tok_by_type(&cmd->tok_head, TOK_REDIRECTION))
			redirections(cmd, fd, tmp, 1);
		else
		{
			dup2(fd[WRITE], STDOUT_FILENO);
			close(fd[READ]);
			dup2(*tmp, STDIN_FILENO);
			close(*tmp);
		}
		execute(cmd);
	}
	else
	{
		close(*tmp);
		close(fd[WRITE]);
		*tmp = fd[READ];
	}
	return (0);
}

int	req_main_proc(t_cmd *cmd)
{
	char	*tmp;

	tmp = ft_malloc(
			ft_strlen(get_tok_content_by_type(&cmd->tok_head, TOK_CMD)) + 1);
	ft_strcpy(tmp, get_tok_content_by_type(&cmd->tok_head, TOK_CMD));
	if (!ft_strcmp("cd", tmp))
		return (builtin_cd(cmd));
	if (!ft_strcmp("export", tmp) && (token_list_len(&cmd->tok_head) != 1))
		return (builtin_export(cmd));
	if (!ft_strcmp("unset", tmp))
	{
		unset(cmd);
		return (0);
	}
	if (!ft_strcmp("exit", tmp))
	{
		builtin_exit(cmd);
		return (0);
	}
	ft_free(tmp);
	return (1);
}

int	pipeline(t_cmd **cmd_head)
{
	int		fd[2];
	pid_t	pid;
	int		tmp;
	t_cmd	*curr;

	curr = (*cmd_head);
	tmp = dup(0);
	pid = 0;
	while (curr != NULL)
	{
		if (!req_main_proc(curr))
		{
			curr = curr->next;
			continue ;
		}
		if (curr->next == NULL)
			gen_last_process(curr, pid, &tmp);
		else
			gen_std_process(curr, fd, pid, &tmp);
		curr = curr->next;
	}
	close(tmp);
	close(fd[WRITE]);
	return (0);
}

void	pipeline_wrapper(t_main *main)
{
	main->env_mat = NULL;
	main->env_mat = fill_env_mat(&main->env_head);
	pipeline(&main->cmd_head);
}
