#include <stdio.h>
#include "incl/minishell.h"

int main(int argc, char **argv, char **envp)
{
	char	*buf;
	int		backup;
	int fd_doc;

	char *path = ft_strjoin("./.heredoc", ft_itoa(1));
	if ((fd_doc = open(path, O_CREAT | O_WRONLY, 0777)) < 0)
		perror("minishell");

	backup = dup(STDOUT_FILENO);
	printf("limiter(reading): %s\n", "e");
	while (1)
	{
		dup2(backup, fd_doc);
		buf = readline("heredoc> ");
		if (!ft_strcmp(buf, "e"))
			break ;
		dup2(fd_doc, STDOUT_FILENO);
		printf("%s\n", buf);
	}
	dup2(backup, fd_doc);
}
