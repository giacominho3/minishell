#include "incl/signals.h"

void	wt_sig(int sig)
{
	struct termios old_input;
	struct termios new_input;

	tcgetattr(STDIN_FILENO, &old_input);
	new_input = old_input;
	new_input.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, TCSANOW, &new_input);
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
//		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	reset_terminal(void)
{
	struct termios attributes;

	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag |= (ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);

}

void	wt_sig1(int sig)
{
	if (sig == SIGQUIT)
		return ;
}
