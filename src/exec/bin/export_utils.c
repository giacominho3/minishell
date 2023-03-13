/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 04:54:58 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 01:01:26 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/builtins.h"

/**
 * @brief check if the arg of a command
 * is valid to be added to the export
 */
int	check_if_valid(char *arg)
{
	if ((arg[0] >= 65 && arg[0] <= 90)
		|| (arg[0] >= 97 && arg[0] <= 122) || arg[0] == 95)
		return (0);
	return (1);
}

/**
 * @param arg
 *
 * @brief check if the arg is valid to be added also to the env
 */
int	not_valid_for_env(char *arg)
{
	if (is_in_strings(61, arg))
		return (0);
	return (1);
}

/**
 * @param cmd ref of the cmd being executed
 * @param arg of the cmd to add to the export
 *
 * @brief adds a single arg to the export and if valid
 * also to the env
 */
void	add_to_export(t_cmd *cmd, char *arg)
{
	ft_add_export(&cmd->main_ref->export_head, arg);
	if (not_valid_for_env(arg))
		return ;
	ft_add_last(&cmd->main_ref->env_head, arg);
	cmd->main_ref->exit_status = 0;
}

/**
 * @param cmd ref of the cmd being executed
 * @return
 *
 * @brief adds all the args of the command to the export
 */
void	add_elements_to_export(t_cmd *cmd)
{
	t_token_list	*curr;

	curr = cmd->tok_head;
	while (curr != NULL)
	{
		if (curr->type == TOK_ARGS)
		{
			if (check_if_valid(curr->token))
			{
				printf("minishell: export: '%s': not a valid indentifier\n",
					curr->token);
				cmd->main_ref->exit_status = 1;
				curr = curr->next;
				continue ;
			}
			add_to_export(cmd, curr->token);
		}
		curr = curr->next;
	}
}
