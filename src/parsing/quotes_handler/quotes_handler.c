#include "../incl/parse.h"

int count_quotes(char *string)
{
	int	cont;
	int	i;

	i = 0;
	cont = 0;
	while (string[i])
	{
		if (string[i] == 34 || string[i] == 39)
			cont++;
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
		if (original[i] == 34 && original[i - 1] != 92)
			keep_single = !keep_single;
		if (original[i] == 39 && original[i - 1] != 92)
			keep_double = !keep_double;
		if (keep_double && original[i] == 34)
			modified[j] = original[i];
		if (keep_single && original[i] == 39)
			modified[j] = original[i];

		printf("modified[%d]: %c\n", j, modified[j]);
		j++;
		i++;
	}
	modified[j] = 0;
	printf("modified: %s\n", modified);
}
//
//bool	keep_quotes_check(t_parse *parse, int offset)
//{
//	if (parse->out[offset] == 34 && parse->out [offset - 1] != 92)
//		parse->double_quotes = !parse->double_quotes;
//	if (parse->out[offset] == 39 && parse->out [offset - 1] != 92)
//		parse->single_quotes = !parse->single_quotes;
//}

void	quotes_handler(t_parse *parse)
{
	int		cont;
	char	*buf;

	parse->single_quotes = false;
	parse->double_quotes = false;
	printf("parse.out: %s\n", parse->out);
	cont = count_quotes(parse->out);
	printf("quotes found: %d\n", cont);
	printf("buf allocated for: %d\n", ((ft_strlen(parse->out) - cont) + 1));
	buf = malloc((ft_strlen(parse->out) - cont) + 1);
	remove_quotes(buf, parse->out);
	printf("string once quotes removed: %s\n", buf);
}