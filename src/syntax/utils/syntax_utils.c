#include "../../../incl/minishell.h"

/**
 *
 * @param str = string to check
 * @param open = opening char to check
 * @param close = closure char to check
 * @return = 1 if each @param open occurrence isn't matched with a @param close char
 *
 * generalized function to check if a char is opened and closed
 * (used for parenthesis and quotes)
 */
int	open_char_syntax(char *str, char open, char close)
{
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

/**
 *
 * @param str = string to check
 * @return = true if the string is valid, and false if it contains invalid chars
 *
 * function to check that the input taken contains just valid characters
 */
bool	is_valid_syntax(char *str)
{
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
