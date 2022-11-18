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
int	open_quotes_syntax(char *str, char quote)
{
	int		i;
	int		cont;
	bool	in_single;
	bool	in_double;

	i = 0;
	cont = 0;
	while (str[i])
	{
		if (str[i] == 39 && !in_single)
			in_double = !in_double;
		if (str[i] == 34 && !in_double)
			in_single = !in_single;
		if (str[i] == quote && (!in_double || !in_single))
		{
			printf("quote found at index: %d\n", i);
			printf("next char: %c\n", str[i + 1]);
			cont++;
			i++;
			continue ;
		}
		i++;
	}
	printf("quotes( %c )cont: %d\n",quote ,cont);
	if ((cont % 2) == 0)
		return (0);
	return (1);
}

/**
 *
 * @param str = string to check
 * @return = true if the string is valid, and false if it contains invalid chars
 *
 * @brief to check that the input taken contains just valid characters
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
