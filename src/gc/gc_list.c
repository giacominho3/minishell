#include "./_incl/AliMalloc.h"

void	ali_malloc_add(t_AliMalloc **gc_head, void	*pointer)
{
	t_AliMalloc *new;
	t_AliMalloc *last;

	last = *(gc_head);
	new = (t_AliMalloc *)malloc(sizeof(t_AliMalloc));
	if (!new)
	{
		perror("AliMalloc");
		exit(EXIT_FAILURE);
	}
	new->address = pointer;
	new->next = NULL;
	if ((*gc_head) == NULL)
	{
		(*gc_head) = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

void	*ft_malloc(size_t size)
{
	void	*pointer;

	pointer = NULL;
	pointer = malloc(size);
	if (!pointer)
	{
		perror("AliMalloc");
		exit(EXIT_FAILURE);
	}
	ali_malloc_add(&AliMalloc, pointer);
	return (pointer);
}

void	remove_AliMalloc_node(t_AliMalloc **gc_head, void *pointer)
{
	t_AliMalloc	*tmp;
	t_AliMalloc	*prev;

	tmp = (*gc_head);
	if (tmp != NULL && tmp->address == pointer)
	{
		(*gc_head) = tmp->next;
		free(tmp->address);
		free(tmp);
		return ;
	}
	while (tmp != NULL && tmp->address != pointer)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	prev->next = tmp->next;
	free(pointer);
	free(tmp);
}

void	ft_free(void *pointer)
{
	remove_AliMalloc_node(&AliMalloc, pointer);
}

void	gc_clear(t_AliMalloc **gc_head)
{
	t_AliMalloc	*curr;
	t_AliMalloc	*next;

	curr = (*gc_head);
	while (curr != NULL)
	{
		next = curr->next;
		if (curr->address != NULL)
			ft_free(curr->address);
		ft_free(curr);
		curr = next;
	}
	*gc_head = NULL;
}
