/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 05:05:51 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/12 05:14:43 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/redirections.h"

int	redir_in(char *file_name)
{
	char	*path;
	int		fd_in;

	path = ft_strjoin("./", ft_trim_mod(file_name, "< "));
	fd_in = open(path, O_RDONLY);
	if (fd_in < 0)
		perror("minishell: redir_in");
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	return (fd_in);
}

void	redir_out(char *file_name, int *tmp)
{
	char	*path;
	int		fd_out;

	path = ft_strjoin("./", ft_trim_mod(file_name, "> "));
	fd_out = open(path, O_CREAT | O_WRONLY, 0644);
	if (fd_out < 0)
		perror("minishell: redir_out: error while opening the file\n");
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	dup2(*tmp, STDIN_FILENO);
	close(*tmp);
}

void	last_proc_handling(int fd[], int *tmp, int test)
{
	dup2(fd[WRITE], STDOUT_FILENO);
	close(fd[READ]);
	dup2(*tmp, test);
	close(*tmp);
}

void	redirections(t_cmd *cmd, int fd[], int *tmp, int proc_type)
{
	t_token_list	*tok_tmp;
	bool			out_redir;
	int				test;

	tok_tmp = cmd->tok_head;
	out_redir = false;
	while (tok_tmp != NULL)
	{
		if (tok_tmp->type == TOK_REDIRECTION)
		{
			if (tok_tmp->token[0] == 60)
				test = redir_in(tok_tmp->token);
			if (tok_tmp->token[0] == 62)
			{
				redir_out(tok_tmp->token, tmp);
				out_redir = true;
			}
		}
		tok_tmp = tok_tmp->next;
	}
	if (out_redir == false && proc_type != 0)
		last_proc_handling(fd, tmp, test);
}
