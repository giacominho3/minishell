#include "../../_incl/tokens.h"

/**
 * @param c char to analyze
 * @return true if it's in the list of metacharacter, false if not
 *
 * @brief check if the char passed as argument is a metacharacter
 */
bool	is_metacharacter(char c)
{
	if (c == 124 || c == 10 || c == 60
		|| c == 62)
		return (true);
	return (false);
}

bool	is_skippable(char c)
{
	if (c == 32 || c == 9)
		return (true);
	return (false);
}

/**
 * @param cmd cmd line string
 * @param i index to the beginning of the token
 *
 * @brief calculates the length of the token that have to be inserted int he tok list
 */
int	calc_tok_len(char *cmd, int i)
{
	int cont;

	cont = 0;
	while (cmd[i] && !is_metacharacter(cmd[i])
		&& !is_skippable(cmd[i]))
	{
		cont++;
		i++;
	}
	return (cont);
}

