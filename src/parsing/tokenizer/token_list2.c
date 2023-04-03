/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:54:08 by gifulvi          #+#    #+#             */
/*   Updated: 2023/03/13 02:10:05 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/tokens.h"

/**
 * @param tok_head head to the token list of a command
 * @return length of the token list
 *
 * @brief calculates the number of tokens inside the list
 */
int	token_list_len(t_token_list **tok_head)
{
	t_token_list	*curr;
	int				cont;

	curr = (*tok_head);
	cont = 0;
	while (curr != NULL)
	{
		cont++;
		curr = curr->next;
	}
	return (cont);
}
