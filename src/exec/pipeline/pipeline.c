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

int	gen_in_process(t_cmd *cmd, int fd[], pid_t pid, int tmp)
{
	pid = fork();

	if (pid < 0)
		return 1;
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd[0]);
		printf("test\n");
//		if (execute())
			return 2;
	}
	else
	{
		close(tmp);
		close(fd[1]);
		tmp = fd[0];
	}
}

void	gen_out_process(t_cmd *cmd, int fd[], pid_t pid, int tmp)
{
	pid = fork();

	if(pid < 0)
		return
}

void	gen_std_process(t_cmd *cmd, int fd[], pid_t pid, int tmp)
{
}

int	test_with_three(t_cmd **cmd_head)
{
	int		fd[2];
	pid_t 	pid;
	int		tmp;
	t_cmd *curr;

	tmp = dup(0);
	while (curr != NULL)
	{
		if (curr->prev == NULL)
			gen_in_process(curr, fd, pid, tmp);
		if (curr->next == NULL)
			gen_out_process(curr, fd, pid, tmp);
		gen_std_process(curr, fd, pid, tmp);
		curr = curr->next;
	}
	close(tmp);
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
