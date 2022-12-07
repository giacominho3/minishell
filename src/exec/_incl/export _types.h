#ifndef MINISHELL_EXPORT__TYPES_H
# define MINISHELL_EXPORT__TYPES_H
# include "../../../incl/minishell.h"

typedef struct	s_export
{
	char	**entries;
	char	**args;
	int		size;
}	t_export;

#endif