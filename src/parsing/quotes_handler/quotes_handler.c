#include "../_incl/parse.h"

int count_quotes_to_remove(char *string)
{
	int		i;
	int		cont;
	bool	keep_single;
	bool	keep_double;

	i = 0;
	cont = 0;
	keep_double = false;
	keep_single = false;
	while (string[i])
	{
		if (string[i] == 39 && !keep_single)
			keep_double = !keep_double;
		if (string[i] == 34 && !keep_double)
			keep_single = !keep_single;
		if ((string[i] == 34 && !keep_double)
			|| (string[i] == 39 && !keep_single))
		{
			i++;
			cont++;
			continue ;
		}
		i++;
	}
	return (cont);
}

void	remove_quotes(char *modified, char *original)
{
	int		i;
	int		j;
	bool	keep_single;
	bool	keep_double;

	i = 0;
	j = 0;
	keep_double = false;
	keep_single = false;
	while (original[i])
	{
		if (original[i] == 39 && !keep_single)
			keep_double = !keep_double;
		if (original[i] == 34 && !keep_double)
			keep_single = !keep_single;
		if ((original[i] == 34 && !keep_double)
			|| (original[i] == 39 && !keep_single))
		{
			i++;
			continue ;
		}
		modified[j] = original[i];
		i++;
		j++;
	}
	modified[j] = 0;
}

/*
		if (original[i] == 34 && original[i - 1] != 92)
			keep_single = !keep_single;
		if (original[i] == 39 && original[i - 1] != 92)
			keep_double = !keep_double;
		if (original[i] == 92 && !keep_single && !keep_double)
		{
			i++;
			modified[j] = original[i];
			i++;
			j++;
			continue ;
		}
		if ((original[i] == 34 && !keep_double) || (original[i] == 39 && !keep_single))
		{
			i++;
			continue ;
		}
		modified[j] = original[i];
		i++;
		j++;
*/
void	quotes_handler(t_parse *parse)
{
	int		i;
	int		cont;
	char	*buf;

	parse->single_quotes = false;
	parse->double_quotes = false;
	printf("parse.out: %s\n", parse->out);
	printf("parse.out len: %d\n", ft_strlen(parse->out));
	cont = count_quotes_to_remove(parse->out);
	printf("quotes to skip found: %d\n", cont);
	printf("buf allocated for: %d\n", ((ft_strlen(parse->out) - cont) + 1));
	buf = malloc((ft_strlen(parse->out) - cont) + 1);
	ft_strcpy(buf, parse->out);
	printf("strcopy test: %s\n", buf);
	remove_quotes(buf, parse->out);
	printf("string once quotes removed: %s\n", buf);
	free(parse->out);
	parse->out = malloc(ft_strlen(buf) + 1);
	i = -1;
	while (buf[++i])
		parse->out[i] = buf[i];
	parse->out[i] = 0;
}
