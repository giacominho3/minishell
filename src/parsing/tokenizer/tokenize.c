#include "../../../incl/minishell.h"

void	find_flags(char *sub_string, t_token_list **head)
{
	int		i;
	bool	quotes;
	int		start;
	int		end;
	char	*tmp;

	i = 0;
	quotes = false;
	while (sub_string[i])
	{
		if (sub_string[i] == 34 || sub_string[i] == 39)
			quotes = !quotes;
		if (sub_string[i] == 45)
			start = i;
		if (sub_string[i] == 32)
			end = i;
	}
	tmp = (char *) malloc((end - start) + 1);
	if (!tmp)
	{
		perror("malloc error\n");
		return ;
	}
	tmp = ft_
}