#include "../../../incl/minishell.h"

int print_syntax_err(int cont_open, int cont_close, char open, char close)
{
	if (cont_open > cont_close)
	{
		printf("test: Minishell: syntax error: '%c' opened but not closed\n", open);
	}
	if (cont_open < cont_close)
	{
		printf("test: Minishell: syntax error: '%c' closed but not opened\n", close);
	}
	return (1);
}

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
	if (open == close)
	{
		if (count_close % 2 == 0)
			return (0);
		return (1);
	}
	if (count_close == count_open)
		return (0);
	return (print_syntax_err(count_open, count_close, open, close));
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
