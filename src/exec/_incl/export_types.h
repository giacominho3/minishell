#ifndef MINISHELL_EXPORT__TYPES_H
# define MINISHELL_EXPORT__TYPES_H
# include "../../../incl/minishell.h"

typedef struct	s_export
{
	char			*name;
	char			*content;
	struct s_export	*next;
	struct s_export	*prev;
}	t_export;

#endif
