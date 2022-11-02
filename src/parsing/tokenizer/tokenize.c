#include "../../../incl/minishell.h"

/**
 *
 * @param sub_string = current command to analyze
 * @param head = head of the token list for the current command
 * this function looks for flags inside the @param sub_string to do
 * so it looks for the pattern: "-*any character* " and it will take
 * every char between the dash and the space, creating a new node inside
 * the token list with the @enum t_tokens value = TOK_FLAGS for the param
 * type and for the param token it will just copy the part matched as flag
 * without dash and space.
 *
 * used ascii:
 * 34 = "
 * 39 = '
 * 45 = -
 * 32 = space
 */
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
	tmp = ft_offset_copy();
}
