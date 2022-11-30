#include "../_incl/pipeline.h"

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

int ft_strlen(char *str)
{
	int cont;

	cont = 0;
	while (str[cont])
		cont++;
	return cont;
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

























char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
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


int	gen_last_process(t_cmd *cmd, int fd[], pid_t pid, int *tmp, char **envp)
{
	pid = fork();
	if (pid < 0)
		return 2;
	if (pid == 0)
	{
		dup2(*tmp, STDIN_FILENO);
		close(*tmp);
		char *path = ft_strjoin("/usr/bin/", cmd->cmd);
		execve(path, cmd->args, envp);
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
		char *path;
		if (ft_strcmp("cat", cmd->cmd) == 0)
			path = ft_strjoin("/bin/", cmd->cmd);
		else
			path = ft_strjoin("/usr/bin/", cmd->cmd);
		execve(path, cmd->args, envp);
		return  (error("error: cannot execute ", path));
	}
	else
	{
		close(*tmp);
		close(fd[WRITE]);
		*tmp = fd[READ];
	}
	return 0;
}

int	pipeline(t_cmd **cmd_head, char **envp)
{
	int		fd[2];
	pid_t 	pid;
	int		tmp;
	t_cmd	*curr;

	curr = (*cmd_head);
	tmp = dup(0);
	while (curr != NULL)
	{
		if (curr->next == NULL)
			gen_last_process(curr, fd, pid, &tmp, envp);
		else
			gen_std_process(curr, fd, pid, &tmp, envp);
		curr = curr->next;
	}
	close(tmp);
	return 0;
}

int main(int argc, char **argv, char **envp)
{
	t_cmd *cmd_head;
	t_cmd *cpy;

	cmd_head = NULL;
	add_cmd_last(&cmd_head, "cat");
	cpy = cmd_head;
	cmd_head->args = malloc(sizeof(char*) * 3);
	cmd_head->args[0] = malloc(sizeof(char) * ft_strlen("/bin/cat"));
	cmd_head->args[0] = "/bin/cat";
	cmd_head->args[1] = malloc(sizeof(char) * ft_strlen("ciao"));
	cmd_head->args[1] = "ciao";
	cmd_head->args[2] = 0;

	add_cmd_last(&cmd_head, "wc");
	cpy = cpy->next;
	cpy->args = malloc(sizeof(char*) * 2);
	cpy->args[0] = malloc(sizeof(char) * ft_strlen("/usr/bin/wc"));
	cpy->args[0] = "/usr/bin/wc";
	cpy->args[1] = 0;

	add_cmd_last(&cmd_head, "wc");
	cpy = cpy->next;
	cpy->args = malloc(sizeof(char*) * 2);
	cpy->args[0] = malloc(sizeof(char) * ft_strlen("/usr/bin/wc"));
	cpy->args[0] = "/usr/bin/wc";
	cpy->args[1] = 0;

	add_cmd_last(&cmd_head, "xargs");
	cpy = cpy->next;
	cpy->args = malloc(sizeof(char*) * 2);
	cpy->args[0] = malloc(sizeof(char) * ft_strlen("/usr/bin/xargs"));
	cpy->args[0] = "/usr/bin/xargs";
	cpy->args[1] = 0;
	pipeline(&cmd_head, envp);
}
