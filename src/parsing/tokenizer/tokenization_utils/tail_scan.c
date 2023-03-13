/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail_scan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 02:27:59 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 02:28:10 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_incl/tokens.h"

int	tail_scan(char *cmd, int i, t_token_list **tok_head)
{
	int	new_index;

	while (cmd[i] && is_skippable(cmd[i]))
		i++;
	new_index = i;
	new_index = scan_redirections(cmd, new_index, tok_head);
	return (new_index);
}
