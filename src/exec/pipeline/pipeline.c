//#include "incl/pipeline.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

# define READ 0
# define WRITE 1

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

int	input_process(int test)
{
	int fd[2];
	pid_t pid;

	if (pipe(fd) == -1)
		return (1);
	close(fd[READ]);
	pid = fork();
	if (pid == 0)
	{
		printf("input process\n");
		test += 5;
		dup2(fd[WRITE], STDOUT_FILENO);
	}
}

int	output_process(int test)
{

}

int	process_gen(int i, int test)
{

}

int	execute(void)
{
	int *fds[2]; //fd[0] reads | fd[1] writes
	int i;
	int test = 0;

	i = 0;
	int pipe_num = 3;

	input_process(test);


}
int main(void)
{
	execute();
}
