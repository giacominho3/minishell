#include "incl/signals.h"

void  wt_sig(int sig)
{
	if (sig == SIGINT) {
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if(sig == SIGQUIT)
	{
		printf("\r");
		rl_on_new_line();
		rl_redisplay();
	}
}