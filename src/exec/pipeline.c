#include "_incl/pipeline.h"

int	pipes_error(int **fds, int pipe_num)
{
	int	i;

	i = 0;
	while (i < pipe_num)
	{
		if (!fds[i])
		{
			i++;
			continue ;
		}
		close(fds[i][READ]);
		close(fds[i][WRITE]);
	}
	return (1);
}

int	error(char *str, char *err)
{
	while (*str)
		write(2, str++, 1);
	if (err)
		while (*err)
			write(2, err++, 1);
	write(2, "\n", 1);
	return (1);
}

int	gen_last_process(t_cmd *cmd, pid_t pid, int *tmp, char **envp)
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
		execute(cmd, envp);
	}
	else
	{
		while (waitpid(-1, NULL, WUNTRACED) != -1);
		close(*tmp);
		*tmp = dup(0);
	}
	return (0);
}

int	gen_std_process(t_cmd *cmd, int fd[], pid_t pid, int *tmp, char **envp)
{
	if (pipe(fd) < 0)
		return 2;
	pid = fork();
	if (pid < 0)
		return 1;
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
		execute(cmd, envp);
	}
	else
	{
		close(*tmp);
		close(fd[WRITE]);
		*tmp = fd[READ];
	}
	return (0);
}

int req_main_proc(t_cmd *cmd)
{
	char	*tmp;

	tmp = malloc(ft_strlen(get_tok_content_by_type(&cmd->tok_head, TOK_CMD)) + 1);
	if (!tmp)
		return 1;
	ft_strcpy(tmp, get_tok_content_by_type(&cmd->tok_head, TOK_CMD));
	if (!ft_strcmp("cd", tmp))
		return (builtin_cd(cmd));
	if (!ft_strcmp("export", tmp) && (token_list_len(&cmd->tok_head) != 1))
		return (builtin_export(cmd));
	if (!ft_strcmp("unset", tmp))
	{
		/* bin_unset(); should return 0 */
		printf("unset\n");
		unset(cmd);
		return 0;
	}
	if (!ft_strcmp("exit", tmp))
	{
		/* bin_exit(); should return 0 */
		printf("exit\n");
		builtin_exit(cmd);
		return 0;
	}
	free(tmp);
	return (1);
}

int	pipeline(t_cmd **cmd_head, char **matrix_env)
{
	int		fd[2];
	pid_t 	pid;
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
			gen_last_process(curr, pid, &tmp, matrix_env);
		else
			gen_std_process(curr, fd, pid, &tmp, matrix_env);
		curr = curr->next;
	}
	close(tmp);
	close(fd[WRITE]);
	return (0);
}

void	pipeline_wrapper(t_main *main)
{
	char	**matrix_env = NULL;

	matrix_env = NULL;
	matrix_env = fill_env_mat(&main->env_head);
	pipeline(&main->cmd_head, matrix_env);

}
