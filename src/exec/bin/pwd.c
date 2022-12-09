#include "../_incl/builtins.h"

int	builtin_pwd(t_cmd *cmd, int fd[], int *tmp_fd)
{
	char *tmp;

	if (cmd->next != NULL)
	{
		if (pipe(fd) < 0)
			return 0;
		dup2(fd[WRITE], STDOUT_FILENO);
		close(fd[READ]);
		dup2(*tmp_fd, STDIN_FILENO);
		close(*tmp_fd);
	}
	if (cont_tok_by_type(&cmd->tok_head, TOK_FLAGS) > 0)
	{
		printf("minishell: pwd: %s: invalid option\n", get_tok_content_by_type(&cmd->tok_head, TOK_FLAGS));
		return (-1);
	}
	tmp = get_content_by_name(&cmd->main_ref->env_head, "PWD");
	printf("%s\n", tmp);
	close(*tmp_fd);
	close(fd[WRITE]);
	*tmp_fd = fd[READ];
	return (0);
}
