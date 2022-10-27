/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:52:50 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/27 20:33:59 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		exit = 0;
	char	*buff;
	int i = 0;
	struct s_env *env_head = NULL;

	copy_env(&env_head, envp);

	while (exit != 1)
	{
		buff = readline("Minishell> ");
		if (!buff)
			return (printf("\nMinishell> exit\n"));
		if (ft_strcmp(buff, "luce") == 0)
			printf("DUCE\n");
		else
			printf("%s\n", buff);
	}
}
