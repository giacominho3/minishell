/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 05:03:25 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/13 01:01:08 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/heredoc.h"

void	remove_file(char *file_name, t_cmd *cmd)
{
	char	*matrix[3];
	char	**envp;

	matrix[0] = "/bin/rm";
	matrix[1] = file_name;
	matrix[2] = 0;
	envp = NULL;
	envp = fill_env_mat(&cmd->main_ref->env_head);
	if (!fork())
	{
		printf("removing: %s\n", file_name);
		if (execve("/bin/rm", matrix, envp) == -1)
			perror("Minishell");
		exit(0);
	}
	ft_free_matrix(envp);
}

/**
 *
 * @param cmd_head
 *
 * @brief removes all the heredoc files generated
 * during the pipeline execution
 */
void	clear_heredoc(t_cmd **cmd_head)
{
	t_cmd			*curr_cmd;
	t_token_list	*curr_tok;

	curr_cmd = (*cmd_head);
	while (curr_cmd != NULL)
	{
		curr_tok = curr_cmd->tok_head;
		while (curr_tok != NULL)
		{
			if (curr_tok->type == TOK_HEREDOC)
				remove_file(curr_tok->token, curr_cmd);
			curr_tok = curr_tok->next;
		}
		curr_cmd = curr_cmd->next;
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
			break ;
		if (!ft_strcmp(limiter, buf))
			break ;
		ft_putstring_fd(fd_doc, buf);
		ft_free(buf);
	}
	free(buf);
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

	if (index < 0)
		return ;
	path = ft_strjoin("./.heredoc", ft_itoa(index));
	file_doc = open(path, O_CREAT | O_WRONLY, 0777);
	if (file_doc < 0)
		perror("minishell");
	reading(limiter, file_doc);
	ft_add_tok_last(tok_head, TOK_HEREDOC, path);
}

// cat <<e <<e
