/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 04:54:43 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/12 04:54:44 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/builtins.h"

int	get_exit_code(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] < 48 || token[i] > 57)
			return (255);
		i++;
	}
	i = ft_atoi(token);
	if (i > 255)
		return (0);
	return (i);
}

void	builtin_exit(t_cmd *cmd)
{
	t_token_list	*value;
	int				code;

	value = cmd->tok_head;
	if (cont_tok_by_type(&value, TOK_FLAGS) >= 1)
		exit(255);
	if (cont_tok_by_type(&value, TOK_ARGS) == 0)
		exit(0);
	while (value != NULL && value->type != TOK_ARGS)
		value = value->next;
	code = get_exit_code(value->token);
	ft_exit(cmd->main_ref);
	exit(code);
}
