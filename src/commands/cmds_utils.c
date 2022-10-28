/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:45:35 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/28 18:47:20 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

void	cmds_node_create(struct s_cmd **head, char *input)
{
	struct s_cmd	*curr;

	curr = (*head);
	curr->out = input;
}