//#include "incl/pipeline.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

int	process_gen(int i, int test)
{
	int	fd[2]; //fd[0] reads | fd[1] writes
	pid_t pid;

	if (pipe(fd) == 0)
		return 0;
	printf("qui\n");
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		test += 5;
		printf("process %d: %d\n", i, getpid());
	}
	else
	{
			close(fd[1]);
			dup2(fd[0], 0);
			waitpid(pid, NULL, 0);
			return (5);
	}
	return (0);
}

int	execute(void)
{
	int	fd[2]; //fd[0] reads | fd[1] writes
	pid_t	*pids;

	pids = malloc(sizeof(pid_t) * 4);
	if (!pids)
	{
		printf("error while allocating pids\n");
		return (1);
	}
	printf("padre: %d\n", getpid());

	// test
	int	test = 0;

	if (pipe(fd) == 0)
		return (1);
	pids[0] = fork();
	int i = 0;
	if (pids[0] == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		test += 5;
		printf("process %d: %d\n", i, getpid());
		return 1;
	}
	while (++i < 3)
		process_gen(i, test);
	pids[4] = fork();
	if (pids[0] == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		test += 5;
		printf("process 4: %d\n", getpid());
		return 1;
	}
	wait(NULL);
	printf("test :%d\n", test);
	return (0);
}
/*
void	pipe_manager(t_main *main)
{
	if (cont_cmd_number(&main->cmd_head))
	{
		execute(&main->cmd_head);
	}
}*/

int main(void)
{
	execute();
}