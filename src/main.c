/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:52:50 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/26 16:05:43 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		exit = 0;
	char	*input;
	int i = -1;
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	while (envp[++i])
		printf("envp[%d]: %s\n", i, envp[i]);
	printf("-------------------\n");
	shell->env = envp;
	i = -1;
	while (shell->env[++i])
		printf("env[%d]: %s\n", i, shell->env[i]);
	while (exit != 1)
	{
		input = readline("Minishell> ");
		input = parse(input);
		if (ft_strcmp(input, "luce") == 0)
			printf("DUCE\n");
		else
			printf("%s\n", input);
	}
}
