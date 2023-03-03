/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:52:50 by tterribi          #+#    #+#             */
/*   Updated: 2022/11/05 11:25:19 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	fancy_init(void)
{
	printf ("\033[0;36m");
	printf("\t███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗\n"
		"\t████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║\n"
		"\t██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║\n"
		"\t██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║\n"
		"\t██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗\n"
		"\t╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝"
		"╚══════╝\n");
	printf("\033[0m\n");
	printf("\033[0;35m");
	printf("\t\t    |Hopefully abb beautiful abb a shell T.T|\n");
	printf("\033[0m\n");
}

void	interpreter(char *input, t_main *main)
{
	if (syntax(input))
		return ;
	if (command_splitter(input, main))
		return ;
	if (tokenizer(&main->cmd_head))
		return ;
	if (parsing(main))
		return ;
	pipeline_wrapper(main);
	clear_cmd_list(&main->cmd_head);
}

void	ft_exit(t_main *main)
{
	clear_env(&main->env_head);
	clear_cmd_list(&main->cmd_head);
	clear_export(&main->export_head);
}

int	main(int argc, char **argv, char **envp)
{
	char	*buff;
	t_main	main;

	(void)argc;
	(void)argv;
	fancy_init();
	main.env_head = NULL;
	main.cmd_head = NULL;
	main.export_head = NULL;
	g_exit_status = 0;
	copy_env(&main.env_head, envp);
	copy_env_to_export(&main.export_head, envp);
	while (1)
	{
		signal(SIGINT, wt_sig);
		signal(SIGQUIT, wt_sig1);
		buff = readline("Minishell> ");
		if (!buff)
		{
			ft_exit(&main);
			free(buff);
			printf("\b\b  \nMinishell> exit");
			return (0);
		}
		add_history(buff);
		if (buff != NULL)
			interpreter(buff, &main);
		free(buff);
	}
}
