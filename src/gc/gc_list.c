/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 05:22:25 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/13 17:57:14 by gifulvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./_incl/AliMalloc.h"

void	ali_malloc_add(t_ali_malloc **gc_head, void	*pointer)
{
	t_ali_malloc	*new;
	t_ali_malloc	*last;

	last = *(gc_head);
	new = (t_ali_malloc *)malloc(sizeof(t_ali_malloc));
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

	if (size < 1)
		return (NULL);
	pointer = NULL;
	pointer = malloc(size);
	if (!pointer)
	{
		perror("AliMalloc");
		exit(EXIT_FAILURE);
	}
	ali_malloc_add(&g_ali_malloc, pointer);
	return (pointer);
}

void	remove_ali_malloc_node(t_ali_malloc **gc_head, void *pointer)
{
	t_ali_malloc	*tmp;
	t_ali_malloc	*prev;

	tmp = (*gc_head);
	if (tmp != NULL && tmp->address == pointer)
	{
		(*gc_head) = tmp->next;
		if (pointer != NULL)
			free(pointer);
		pointer = NULL;
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
	if (pointer != NULL)
		free(pointer);
	pointer = NULL;
	free(tmp);
	tmp = NULL;
}

void	ft_free(void *pointer)
{
	remove_ali_malloc_node(&g_ali_malloc, pointer);
	pointer = NULL;
}

void	gc_clear(t_ali_malloc **gc_head)
{
	t_ali_malloc	*curr;
	t_ali_malloc	*next;

	curr = (*gc_head);
	if (curr == NULL)
		exit(EXIT_FAILURE);
	while (curr != NULL)
	{
		next = curr->next;
		if (curr->address != NULL)
		{
			if (curr->address != NULL)
			{
				free(curr->address);
				curr->address = NULL;
			}
		}
		if (curr != NULL)
		{
			free(curr);
			curr = NULL;
		}
		curr = next;
	}
	*gc_head = NULL;
}
