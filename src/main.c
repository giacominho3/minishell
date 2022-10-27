/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:52:50 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/27 12:52:18 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		exit = 0;
	char	*input;
	int i = 0;
	struct s_env *env_head = NULL;

	copy_env(&env_head, envp);

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
