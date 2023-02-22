#include "../_incl/heredoc.h"

void	remove_file(char *file_name)
{

}

/**
 *
 * @param cmd_head
 *
 * @brief removes all the heredoc files generated
 * during the pipeline execution
 */
void	clear_heredoc(t_cmd *cmd_head)
{
	t_token_list	*curr;

	curr = cmd_head->tok_head;
	while (curr != NULL)
	{
		if (curr->type == TOK_HEREDOC)
			remove_file(curr->token);
		curr = curr->next;
	}
}

void	ft_putstring_fd(int fd, char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		write(fd, &string[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

void	reading(char *limiter, int fd_doc)
{
	char	*buf;

	while (1)
	{
		buf = readline("heredoc> ");
		if (!buf)
		{
			perror("minishell");
			return ;
		}
		if (!ft_strcmp(limiter, buf))
			break ;
		ft_putstring_fd(fd_doc, buf);
		free(buf);
	}
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
