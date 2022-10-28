#include "../../../incl/minishell.h"

int	open_char_syntax(char *str, char c)
{
	/* generalized function to check if a char is opened and closed
	* (used for quotes and parenthesis) */
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while(str[i])
	{
		if (str[i] == c)
			quotes++;
		i++;
	}
	if ((quotes % 2) == 0)
		return (0);
	return (1);
}

bool	is_valid_syntax(char *str)
{
	/* function to check that the input taken contains just valid characters */
	int		i;

	i = 0;
	while(str[i])
	{
		if (!((str[i] >= 32 && str[i] <= 126) || str[i] == 10))
			return (false);
		i++;
	}
	return (true);
}
