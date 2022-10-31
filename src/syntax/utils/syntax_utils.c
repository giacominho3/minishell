#include "../../../incl/minishell.h"

int	open_quotes_syntax(char *str, char c)
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

int	open_parenthesis_syntax(char *str, char open, char close)
{
	/* generalized function to check if a char is opened and closed
	* (used for quotes and parenthesis) */
	int	i;
	int	count_open;
	int	count_close;

	i = 0;
	count_open = 0;
	count_close = 0;
	while(str[i])
	{
		if (str[i] == open)
			count_open++;
		if (str[i] == close)
			count_close++;
		i++;
	}
	if (count_close == count_open)
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
