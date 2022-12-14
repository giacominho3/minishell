#include "../../_incl/tokens.h"

char	*get_redir(char *cmd, int i)
{
	char	*ret;
	int		index;
	int		len;
	char	c;

	c = cmd[i];
	i++;
	while(cmd[i] && (cmd[i] == 32 || cmd[i] == 9))
		i++;
	len = 0;
	index = i;
	while (cmd[index] && !is_metacharacter(cmd[i]))
	{
		len++;
		index++;
	}
	ret = malloc(len + 2);
	ret[0] = c;
	index = 1;
	while (cmd[index] && !is_metacharacter(cmd[i]))
	{
		ret[index] = cmd[i];
		index++;
		i++;
	}
	ret[index] = 0;
	return (ret);
}

char	*get_heredoc(char *cmd, int i)
{
	char	*ret;
	int		index;
	int		len;

	printf("heredoc cursor on: %c\n", cmd[i]);
	printf("heredoc cursor on(next): %c\n", cmd[i+1]);
	i += 2;
	while(cmd[i] && (cmd[i] == 32 || cmd[i] == 9))
		i++;
	len = 0;
	index = i;
	printf("index: %d\n", len);
	while (cmd[index] && !is_metacharacter(cmd[i]))
	{
		len++;
		index++;
	}
	printf("len: %d\n", len);
	ret = malloc(len + 3);
	ret[0] = '<';
	ret[1] = '<';
	index = 2;
	while(cmd[i] && (cmd[i] == 32 || cmd[i] == 9))
	{
		ret[index] = cmd[i];
		index++;
		i++;
	}
	while (cmd[i] && !is_metacharacter(cmd[i]))
	{
		ret[index] = cmd[i];
		index++;
		i++;
	}
	ret[index] = 0;
	return (ret);
}

bool	not_operator(char c)
{
	if (c != 60 && c != 62 && c != 124)
		return (true);
	return (false);
}

int	calc_arg_len(char *cmd, int i)
{
	int		cont;
	bool	single_q;
	bool	double_q;

	cont = 0;
	single_q = false;
	double_q = false;
	while (cmd[i] && not_operator(cmd[i]))
	{
		if (cmd[i] == 39)
			single_q = !single_q;
		if (cmd[i] == 34)
			double_q = !double_q;
		if (cmd[i] == 45 && !single_q && !double_q)
			break ;
		cont++;
		i++;
	}
	return (cont);
}


int	skip_spaces(char *cmd, int i)
{
	while (cmd[i] && !is_metacharacter(cmd[i]) && is_skippable(cmd[i]))
		i++;
	return (i);
}
