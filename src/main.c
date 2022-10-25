/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:52:50 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/24 19:23:15 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"


int	main(int argc, char **argv)
{
	int		exit = 0;
	char	*input;

	while (exit != 1)
	{
		input = readline("Minishell> ");
		if (ft_strcmp(input, "luce") == 0)
			printf("DUCE\n");
		else
			printf("taken input: %s\n", input);
	}
}
