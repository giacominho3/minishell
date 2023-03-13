/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AliMalloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 05:22:09 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 03:04:55 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIMALLOC_H
# define ALIMALLOC_H

# include "../../../incl/minishell.h"

typedef struct s_ali_malloc
{
	void				*address;
	struct s_ali_malloc	*next;
}	t_ali_malloc;

void	*ft_malloc(size_t size);
void	ft_free(void *pointer);
void	gc_clear(t_ali_malloc **gc_head);

#endif //MINISHELL_GARBAGE_COLLECTOR_H
