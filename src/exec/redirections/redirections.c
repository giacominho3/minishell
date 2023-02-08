#include "../_incl/redirections.h"

void	redir_in(char *file_name, int fd[], int *tmp)
{
	char	*path;
	int		fd_in;

	path = ft_strjoin("./", file_name);
	if ((fd_in = open(path, O_RDONLY)) < 0)
		perror("minishell: redir_in: \n");
	*tmp = fd_in;
	dup2(fd[WRITE], STDOUT_FILENO);
	close(fd[READ]);
	dup2(*tmp, STDIN_FILENO);
	close(*tmp);
}

void	redir_out(char *file_name, int *tmp)
{
	char	*path;
	int		fd_out;

	printf("file_name after trim: %s\n", file_name);
	write(2, "redir_out\n", 10);
	path = ft_strjoin("./", ft_trim_mod(file_name, ">"));
	if ((fd_out = open(path, O_CREAT | O_WRONLY)) < 0)
		perror("minishell: redir_out: error while opening the file\n");
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	dup2(*tmp, STDIN_FILENO);
	close(*tmp);
}

void	redirections(t_cmd *cmd, int fd[], int *tmp)
{
	t_token_list *tok_tmp;

	tok_tmp = cmd->tok_head;
	printf("___redirections___\n");
	while (tok_tmp != NULL)
	{
		if (tok_tmp->type == TOK_REDIRECTION)
		{
			if (tok_tmp->token[0] == 60)
				redir_in(tok_tmp->token, fd, tmp);
			if (tok_tmp->token[0] == 62)
				redir_out(tok_tmp->token, tmp);
		}
		tok_tmp = tok_tmp->next;
	}
}
