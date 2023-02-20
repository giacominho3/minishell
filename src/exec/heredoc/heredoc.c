#include "../_incl/heredoc.h"
#include "../../../incl/minishell.h"

void	reading(char *limiter, int fd_doc)
{
	char	*buf;
	int		backup;

	backup = dup(STDOUT_FILENO);
	printf("limiter(reading): %s\n", limiter);
	while (1)
	{
		dup2(backup, fd_doc);
		buf = readline("heredoc> ");
		if (!ft_strcmp(buf, limiter))
			break ;
		dup2(fd_doc, STDOUT_FILENO);
		printf("%s\n", buf);
//		int diff = ft_strcmp(buf, limiter);
//		fprintf(stderr, "%d\n", diff);
	}
	dup2(backup, fd_doc);
}

/**
 *
 * @param cmd cmd line that is being read from the tokenizer
 * @param index cursor index on the cmd line
 *
 * @brief heredoc is called during tokenization
 * ad swap the heredoc token (<<'limiter') with
 * the name of the heredoc file that is created
 * for that invocation ('.heredocX' where X is the
 * curr val of cursor)
 *
 * \example
 * cat << end --> cat .heredoc4
 */
void	heredoc(char *limiter, int index, t_token_list **tok_head)
{
	int		file_doc;
	char	*path;

	printf("___HEREDOC___\n");
	if (index < 0)
		return ;
	printf("limiter(heredoc): %s\n", limiter);
	path = ft_strjoin("./.heredoc", ft_itoa(index));
	if ((file_doc = open(path, O_CREAT | O_WRONLY, 0777)) < 0)
		perror("minishell");
	reading(limiter, file_doc);
	ft_add_tok_last(tok_head, TOK_HEREDOC, path);
	printf("_____________\n");
}
