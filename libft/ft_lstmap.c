/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:16:32 by gifulvi          #+#    #+#             */
/*   Updated: 2022/01/19 19:17:27 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp_new;

	new = ft_malloc(sizeof(t_list));
	temp_new = new;
	while (lst != 0 && lst->content != 0)
	{
		new->content = ft_malloc(sizeof(lst->content));
		if (new->content == 0)
			return (0);
		new->content = ((*f)(lst->content));
		new->next = ft_malloc(sizeof(t_list));
		if (new->next == 0)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		lst = lst->next;
		if (lst != 0)
			new = new->next;
	}
	ft_free(new->next);
	new->next = 0;
	return (temp_new);
}
