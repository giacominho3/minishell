#include "../../_incl/tokens.h"

char	*get_redir(char *cmd, int i, int offset)
{
	char	*ret;
	int		index;

	ret = malloc(offset + 1);
	index = 0;
	while (cmd[i] && i < offset)
	{
		ret[index] = cmd[i];
		index++;
		i++;
	}
	ret[index] = 0;
	return (ret);
}
