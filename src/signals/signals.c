/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoggi <rpoggi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:13:41 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 17:33:32 by rpoggi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/signals.h"

void	wt_sig(int sig)
{
	struct termios	old_input;
	struct termios	new_input;

	tcgetattr(STDIN_FILENO, &old_input);
	new_input = old_input;
	new_input.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, TCSANOW, &new_input);
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}
