#include "../../incl/minishell.h"

/**
 *
 * @param c = first character of a variable name
 * @return true if @pram c is considered valid ,else, false
 *
 * c can be just a letter of the alphabet so we could say that
 * c must be >= 65 && <= 90 and also >= 97 && <= 122, also '_'
 * are accepted so we c can also be == 95
 */

bool	valid_var_name(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 95)
		return (true);
	return (false);
}
