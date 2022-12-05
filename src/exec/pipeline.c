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
		return 2;
	if (pid == 0)
	{
		dup2(*tmp, STDIN_FILENO);
		close(*tmp);
		execute(cmd, envp);
	}
	else
	{
		close(*tmp);
		while (waitpid(-1, NULL, WUNTRACED) != -1);
		*tmp = dup(0);
	}
	return 0;
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
		dup2(fd[WRITE], STDOUT_FILENO);
		close(fd[READ]);
		dup2(*tmp, STDIN_FILENO);
		close(*tmp);
		execute(cmd, envp);
		return  (error("error: cannot execute ", "diocane"));
	}
	else
	{
		close(*tmp);
		close(fd[WRITE]);
		*tmp = fd[READ];
	}
	return 0;
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
		if (curr->next == NULL)
			gen_last_process(curr, pid, &tmp, matrix_env);
		else
			gen_std_process(curr, fd, pid, &tmp, matrix_env);
		curr = curr->next;
	}
	close(tmp);
	return 0;
}

void	pipeline_wrapper(t_main *main)
{
	char	**matrix_env = NULL;
//	int		i;

	matrix_env = fill_env_mat(&main->env_head);
	//debug print
//	printf("___print_env_mat___\n");
//	i = 0;
//	while (matrix_env[i])
//	{
//		printf("matrix_env[%d]: %s\n", i, matrix_env[i]);
//		i++;
//	}
//	printf("------------------\n");
	//---------------------------------------//
	pipeline(&main->cmd_head, matrix_env);
//	ft_free_matrix(matrix_env);
}
