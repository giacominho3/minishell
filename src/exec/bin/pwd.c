/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 05:01:55 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/12 05:02:04 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/builtins.h"

int	builtin_pwd(t_cmd *cmd)
{
	char	*tmp;

	if (cont_tok_by_type(&cmd->tok_head, TOK_FLAGS) > 0)
	{
		printf("minishell: pwd: %s: invalid option\n",
			get_tok_content_by_type(&cmd->tok_head, TOK_FLAGS));
		return (1);
	}
	tmp = get_content_by_name(&cmd->main_ref->env_head, "PWD");
	printf("%s\n", tmp);
	return (0);
}
