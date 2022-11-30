#include "../../_incl/tokens.h"

int	ft_cntarg(char *s)
{
	int	i;
	int	cntr;
	int	quotes;

	i = 0;
	cntr = 0;
	quotes = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i] == '"' && quotes == 0)
		{
			quotes = 1;
			i++;
		}
		if (s[i - 1] == '"' && s[i - 2] != ' ')
			cntr--;
		if (s[i] == '"' && quotes == 1)
		{
			quotes = 0;
			i++;
		}
		if (s[i] && quotes == 0)
			cntr++;
		while (s[i] && s[i] != ' ' && s[i] != '"')
			i++;
	}
	return (cntr);
}

char	**ft_split_args(char *str)
{
	int		i;
	int		j;
	int		cont;
	char	**args;

	i = 0;
	j = 0;
	args = (char **)malloc(sizeof(char *) * ft_cntarg(str) + 1);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		cont = i;
		while (str[i] && str[i] != ' ' && str[i] != '"')
			i++;
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
				i++;
			if(str[i + 1] != ' ')
			{
				while(str[i] != ' ')
					i++;
			}
			i++;
			args[j] = ft_strndup(str + cont, i - cont);
			j++;
		}
		else if (i > cont)
		{
			args[j] = ft_strndup(str + cont, i - cont);
			j++;
		}
	}
	return(args);
}
