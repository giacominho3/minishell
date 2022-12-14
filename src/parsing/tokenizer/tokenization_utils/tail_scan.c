#include "../../_incl/tokens.h"

int	tail_scan(char *cmd, int i, t_token_list **tok_head)
{
	int	new_index;


	while (cmd[i] && is_skippable(cmd[i]))
		i++;
	printf("cursor on tail beginning: %c\n", cmd[i]);
	new_index = i;
	new_index = scan_redirections(cmd, new_index, tok_head);
	printf("tail new index: %d\n", new_index);
	return (new_index);
}

// cat -e makefile << e
// 0 1 2 3 45678910
//cattamelotutto -eradasds dio merda mannaggia la madonna << molto porca
//echo	suca
