#ifndef MINISHELL_GARBAGE_COLLECTOR_H
# define MINISHELL_GARBAGE_COLLECTOR_H

# include "../../../incl/minishell.h"

typedef struct s_AliMalloc
{
	void				*address;
	struct s_AliMalloc	*next;
}	t_AliMalloc;

void	*ft_malloc(size_t size);
void	*ft_free(void *pointer)
void	gc_clear(t_AliMalloc **gc_head);

#endif //MINISHELL_GARBAGE_COLLECTOR_H
