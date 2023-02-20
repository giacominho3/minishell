#include "../_incl/redirections.h"

int	redir_in(char *file_name)
{
	char	*path;
	int		fd_in;

	printf("redir_in\n");
	printf("filename: %s\n", file_name);
	path = ft_strjoin("./", ft_trim_mod(file_name, "< "));
	printf("path name: %s\n", path);
	if ((fd_in = open(path, O_RDONLY)) < 0)
	{
		printf("fd_in: %d\n", fd_in);
		perror("minishell: redir_in");
	}
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	return (fd_in);
}

void	redir_out(char *file_name, int fd[], int *tmp)
{
	char	*path;
	int		fd_out;

	printf("redir_out\n");
	path = ft_strjoin("./", ft_trim_mod(file_name, "> "));
	if ((fd_out = open(path, O_CREAT | O_WRONLY)) < 0)
		perror("minishell: redir_out: error while opening the file\n");
	dup2(fd_out, STDOUT_FILENO);
	close(fd[READ]);
	dup2(*tmp, STDIN_FILENO);
	close(*tmp);
}

void	redirections(t_cmd *cmd, int fd[], int *tmp, int proc_type)
{
	t_token_list	*tok_tmp;
	bool			out_redir;
	int 			test;

	tok_tmp = cmd->tok_head;
	out_redir = false;
	printf("___redirections___\n");
	while (tok_tmp != NULL)
	{
		if (tok_tmp->type == TOK_REDIRECTION)
		{
			if (tok_tmp->token[0] == 60)
				test = redir_in(tok_tmp->token);
			if (tok_tmp->token[0] == 62)
			{
				redir_out(tok_tmp->token, fd, tmp);
				out_redir = true;
			}
		}
		tok_tmp = tok_tmp->next;
	}
	if (out_redir == false && proc_type != 0)
	{
		dup2(fd[WRITE], STDOUT_FILENO);
		close(fd[READ]);
		dup2(*tmp, test);
		close(*tmp);
		printf("here\n");
	}
	write(2, "_______out________\n", ft_strlen("_______out________\n"));
}
