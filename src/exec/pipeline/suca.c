# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

# define READ 0
# define WRITE 1

int main(void)
{
	int fd[3][2];
	int i = 0;

	while (i < 3)
	{
		if (pipe(fd[i]) == -1)
			return 1;
		i++;
	}

	int pid1 = fork();
	if (pid1 < 0)
		return 2;
	if (pid1 == 0)
	{
		close(fd[0][WRITE]);
		close(fd[1][READ]);
		close(fd[2][READ]);
		close(fd[2][WRITE]);
		int x;
		if (read(fd[0][READ], &x, sizeof(int)) < 0)
			return 3;
		x += 5;
		if (write(fd[1][WRITE], &x, sizeof(int)) < 0)
			return 4;
		close(fd[0][READ]);
		close(fd[1][WRITE]);
		return 0;
	}

	int pid2 = fork();
	if (pid2 < 0)
		return 5;
	if (pid2 == 0)
	{
		close(fd[0][READ]);
		close(fd[0][WRITE]);
		close(fd[1][WRITE]);
		close(fd[2][READ]);
		int x;
		if (read(fd[1][READ], &x, sizeof(int)) < 0)
			return 6;
		x += 5;
		if (write(fd[2][WRITE], &x, sizeof(int)) < 0)
			return 7;
		close(fd[1][READ]);
		close(fd[2][WRITE]);
		return 0;
	}

	close(fd[0][READ]);
	close(fd[1][READ]);
	close(fd[1][WRITE]);
	close(fd[2][WRITE]);
	int x = 0;
	if (write(fd[0][WRITE], &x, sizeof(int)) < 0)
		return 8;
	if (read(fd[2][READ], &x, sizeof(int)) < 0)
		return 9;
	close(fd[0][WRITE]);
	close(fd[2][READ]);
	printf("x: %d\n", x);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
