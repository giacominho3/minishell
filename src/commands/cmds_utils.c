#include "../../incl/minishell.h"

/**
 *
 * @param input = string in which we look for a command
 * @param offset = starting index of the research
 * @return = len of the command
 * determinate the len of a command by navigating the string until it finds
 * a command separator
 */
int	cmd_len(char *input, int offset)
{
	int		cont;
	bool	quotes;
	bool	parent;

	cont = 0;
	quotes = false;
	parent = false;
	printf("input: %s\n", input);
	printf("offset = %d\n", offset);
	offset += skip_intial_spaces(input);
	printf("offset = %d\n", offset);
	while(input[offset])
	{
		if (input[offset] == 34 || input[offset] == 39)
			quotes = !quotes;
		if (input[offset] == 40)
			quotes = true;
		if (input[offset] == 41)
			quotes = false;
		if (cmd_split(input, offset) && !quotes && !parent)
		{
			cont++;
			return (cont);
		}
		cont++;
		offset++;
	}
	return (cont);
}

bool	cmd_split(char *str, int index)
{
	if (str[index] == '|')
		return (true);
	if (str[index] == '|' && str[index + 1] == '|')
		return (true);
	if (str[index] == '&' && str[index + 1] == '&')
		return (true);
	if (str[index] == ';')
		return (true);
	return (false);
}


void	ft_cmdcpy(char *dest, char *src, int len, int offset)
{
	int	i;

	i = 0;
	while (src[offset] && src[offset] == 32)
		offset++;
	while(src[offset] && i < len)
	{
		dest[i] = src[offset];
		i++;
		offset++;
	}
	dest[i] = 0;
}
