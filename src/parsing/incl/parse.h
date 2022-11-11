#ifndef MINISHELL_PARSE_H
# define MINISHELL_PARSE_H
# include "../../../incl/minishell.h"

typedef struct s_main t_main;

typedef struct	s_parse
{
	bool	extend;
	bool	single_quotes;
	bool	double_quotes;
	char	*input_string;
	char	*extended_string;
}	t_parse;

bool	var_end_name(char c);
int 	parse(char *str, t_main *main);
int		logic_skip(char *str, int index);
bool	sep_conditions(char *str, int index);
void	init_parse(char *input, t_parse *parse);

#endif
