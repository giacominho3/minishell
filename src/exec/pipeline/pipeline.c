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

int	recursive_pipeline(t_cmd *cmd)
{
	pid_t	c_pid;

	if (cmd == NULL)
		return (5);
	if (cmd->prev == NULL)
	{
		c_pid = fork();
		if (c_pid < 0)
			return (1);
		if (c_pid == 0)
		{
			dup2(cmd->fd[WRITE], STDOUT_FILENO);
			dup2(cmd->fd[READ], STDIN_FILENO);
			close(cmd->fd[READ]);
			printf("%s, ", cmd->cmd);
			exit(0);
		}
		waitpid(c_pid, NULL, 0);
		return (recursive_pipeline(cmd->next));
	}
	else if (cmd->next == NULL)
	{
		c_pid = fork();
		if (c_pid < 0)
			return (1);
		if (c_pid == 0)
		{
			close(cmd->prev->fd[WRITE]);
			dup2(cmd->fd[WRITE], STDOUT_FILENO);
			close(cmd->fd[WRITE]);
			dup2(cmd->fd[READ], STDIN_FILENO);
			printf("%s, ", cmd->cmd);

			//get fd[READ] content
			char line[99999];
			char buff[2];
			int i = 0;
			line[0] = 0;
			while (read(cmd->fd[READ], &buff[0], 1) == 0)
			{
				line[i] = buff[0];
				line[i + 1] = 0;
				i++;
			}
			line[i] = 0;
			printf("out: %s\n", line);
			exit(0);
		}
		waitpid(c_pid, NULL, 0);
		return (1);
	}
	else
	{
		c_pid = fork();
		if (c_pid < 0)
			return (1);
		if (c_pid == 0)
		{
			close(cmd->prev->fd[WRITE]);
			dup2(cmd->fd[READ], STDIN_FILENO);
			dup2(cmd->fd[WRITE], STDIN_FILENO);

			//get fd[READ] content
			char line[99999];
			char buff[2];
			int i = 0;
			line[0] = 0;
			while (read(cmd->fd[READ], &buff[0], 1) == 0)
			{
				line[i] = buff[0];
				line[i + 1] = 0;
				i++;
			}
			line[i] = 0;
			printf("%s, ", line);
			close(cmd->fd[READ]);
			exit(0);
		}
		waitpid(c_pid, NULL, 0);
		return (recursive_pipeline(cmd->next));
	}
}

void	init_pipes(t_cmd **cmd_head)
{
	t_cmd	*curr;

	curr = (*cmd_head);
	while (curr != NULL)
	{
		if (pipe(curr->fd) == -1)
			return ;
		curr = curr->next;
	}
}

int	execute(t_cmd **cmd_head)
{
	int i;
	int num = 0;

	t_cmd	*head_cpy;

	head_cpy = (*cmd_head);
	int pipe_num = 2;

	init_pipes(cmd_head);
	recursive_pipeline(head_cpy);
	return 5;
//	input_process(test);
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