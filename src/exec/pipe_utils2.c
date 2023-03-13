/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 05:19:07 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 02:50:13 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_incl/pipeline.h"

int	calc_env_x(t_env **env_head)
{
	t_env	*curr;
	int		max_x_cont;
	int		curr_x_len;

	max_x_cont = 0;
	curr = (*env_head);
	while (curr != NULL)
	{
		curr_x_len = ft_strlen(curr->name) + ft_strlen(curr->content) + 1;
		if (curr_x_len > max_x_cont)
			max_x_cont = curr_x_len;
		curr = curr->next;
	}
	return (max_x_cont);
}

int	env_len(t_env **env_head)
{
	t_env	*curr;
	int		cont;

	cont = 0;
	curr = (*env_head);
	while (curr != NULL)
	{
		curr = curr->next;
		cont++;
	}
	return (cont);
}
