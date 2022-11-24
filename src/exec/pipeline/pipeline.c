//#include "incl/pipeline.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

# define READ 0
# define WRITE 1

typedef struct	s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
	char			*out;
	int				cmd_num;
	int				fd[2];
} t_cmd;

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	while (src[i])
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	ft_set_cmd(struct s_cmd *node, char *cmd)
{
	if (!cmd)
		return ;
	node->cmd = ft_strdup(cmd);
}

void	add_cmd_last(struct s_cmd **head, char *cmd)
{
	struct s_cmd	*new;
	struct s_cmd	*last;

	last = (*head);
	new = (struct s_cmd *) malloc(sizeof(struct s_cmd));
	if (!new)
	{
		printf("add_cmd_last: error while allocating new node: cmd: (%s)\n", cmd);
		return ;
	}
	ft_set_cmd(new, cmd);
	new->next = NULL;
	if ((*head) == NULL)
	{
		new->prev = NULL;
		(*head) = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
}

//pipes

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

int	exec_pipe(t_cmd *cmd)
{
	pid_t pid;
}

int iterative_pipes(t_cmd **cmd_head)
{
	int i;
	int *fds[2];
	t_cmd *curr;

	while (i < 2)
	{
		if (pipe(fds[i]) == -1)
			return (1);
		i++;
	}
	curr = (*cmd_head)
	while (curr != NULL)
	{
		exec_pipe();
	}
}


int	execute(t_cmd **cmd_head)
{
	int i;
	int num = 0;

	t_cmd	*head_cpy;

	head_cpy = (*cmd_head);
	int pipe_num = 2;
	iterative_pipes();
	return 5;
//	input_process(test);
}


int	test_with_three()
{
	int	fd[3][2];
	int pid1;
	int pid2;
	int pid3;
	int i = 0;

	while (i < 3)
	{
		if (pipe(fd[i]) == -1)
			return 1;
		i++;
	}
	if ((pid1 = fork()) < 0)
		return 2;
	if (pid1 == 0)
	{
		close(fd[2][WRITE]);
		close(fd[2][READ]);
		close(fd[1][WRITE]);
		close(fd[0][READ]);
		int x = 0;
		dup2();
	}
}




int main(void)
{
	t_cmd *cmd_head;

	cmd_head = NULL;
	add_cmd_last(&cmd_head, "echo");
	add_cmd_last(&cmd_head, "cat");
	add_cmd_last(&cmd_head, "ls");
	if (execute(&cmd_head) == 5)
		printf("exec gone well\n");
}
