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

void	fancy_init(t_main *main)
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
	printf("\t\t    |Hopefully as beautiful as a shell T.T|\n");
	printf("\033[0m\n");
	main->env_head = NULL;
	main->cmd_head = NULL;
	main->export_head = NULL;
	main->exit_status = 0;
	AliMalloc = NULL;
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
	clear_cmd_list(&main->cmd_head); //the execve matrix free has been commented since was causing segfault on ubuntu
}

void	ft_exit(t_main *main)
{
	if (main->env_head)
		clear_env(&main->env_head);
	if (main->cmd_head)
		clear_cmd_list(&main->cmd_head);
	printf("adexit:\n");
	if (main->export_head)
		clear_export(&main->export_head);
	if (main->env_head)
		print_env(&main->env_head);
	printf("iasdexit2\n");
	gc_clear(&AliMalloc);
	printf("asdexit3\n");
}

int	main(int argc, char **argv, char **envp)
{
	char	*buff;
	t_main	main;

	(void)argc;
	(void)argv;
	fancy_init(&main);
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
			ft_free(buff);
			return (printf("\b\b  \nMinishell> exit"));
		}
		if (ft_strlen(buff) == 0)
			continue ;
		add_history(buff);
		if (buff != NULL)
			interpreter(buff, &main);
		ft_free(buff);
	}
}
