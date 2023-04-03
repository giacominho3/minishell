/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:52:50 by gifulvi          #+#    #+#             */
/*   Updated: 2023/04/03 16:45:41 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	init(t_main *main)
{
	printf ("\033[0;35m");
	printf("\t\t\tM I N I S H E L L\n");
	printf("\033[0m\n");
	g_ali_malloc = NULL;
	main->env_head = NULL;
	main->cmd_head = NULL;
	main->export_head = NULL;
	main->exit_status = 0;
}

void	interpreter(char *input, t_main *main)
{
	if (syntax(input))
		return ;
	if (command_splitter(input, main))
	{
		clear_cmd_list(&main->cmd_head);
		return ;
	}
	if (tokenizer(&main->cmd_head))
	{
		clear_heredoc(&main->cmd_head);
		clear_cmd_list(&main->cmd_head);
		return ;
	}
	if (parsing(main))
	{
		clear_cmd_list(&main->cmd_head);
		return ;
	}
	pipeline_wrapper(main);
	clear_heredoc(&main->cmd_head);
	clear_cmd_list(&main->cmd_head);
}

void	ft_exit(t_main *main)
{
	if (!main)
		return ;
	gc_clear(&g_ali_malloc);
	printf("\b\b  \nMinishell> exit");
}

int	main(int argc, char **argv, char **envp)
{
	char	*buff;
	t_main	main;

	(void)argc;
	(void)argv;
	init(&main);
	copy_env(&main.env_head, envp);
	copy_env_to_export(&main.export_head, envp);
	signal(SIGINT, wt_sig);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		buff = readline("Minishell> ");
		if (!buff)
		{
			ft_exit(&main);
			return (1);
		}
		if (ft_strlen(buff) == 0)
			continue ;
		add_history(buff);
		interpreter(buff, &main);
		free(buff);
	}
}
