#include "../../_incl/tokens.h"

int	tail_scan(char *cmd, int i, t_token_list **tok_head)
{
	int	new_index;

	new_index = i;

	write(1, "a\n", 2);
	i = new_index;
	new_index += scan_redirections(cmd, new_index, tok_head);
	return (new_index);
}
