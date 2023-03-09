/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:25:07 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/09 03:25:08 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_incl/commands.h"

/**
 * @brief debug function (print the whole command list)
 */
void	print_cmd(t_cmd **head)
{
	struct s_cmd	*tmp;

	tmp = (*head);
	while (tmp != NULL)
	{
		printf("%s\n", tmp->cmd);
		tmp = tmp->next;
	}
}

/**
 *
 * @param input string read by readline
 * @param main main struct
 *
 * @brief take the input from readline and split it in commands inside
 * the t_cmd list and then checks the syntax of each command
 */
int	command_splitter(char *input, t_main *main)
{
	char	*cmd;
	int		i;

	i = 0;
	while (input[i] != 0)
	{
		cmd = (char *)ft_malloc(cmd_len(input, i) + 1);
		if (!cmd)
		{
			perror("tokenizer.c:97:100 error while allocating cmd");
			return (1);
		}
		ft_cmdcpy(cmd, input, cmd_len(input, i), i);
		i += cmd_len(input, i);
		add_cmd_last(&main->cmd_head, main, cmd);
		ft_free(cmd);
	}
	return (0);
}
