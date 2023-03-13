/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 04:07:02 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/09 04:07:15 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/builtins.h"

int	check_echo_flag(char *flag)
{
	int	i;

	i = 1;
	while (flag[i])
	{
		if (flag[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

bool	flag_check(char *string)
{
	int	i;

	i = 1;
	if (string[0] != '-')
		return (false);
	while (string[i])
	{
		if (string[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

void	echo_print(t_cmd *cmd)
{
	t_token_list	*curr;

	curr = cmd->tok_head;
	while (curr != NULL)
	{
		if (curr->type == TOK_ARGS && !strcmp("$?", curr->token))
		{
			printf("%d", cmd->main_ref->exit_status);
			curr = curr->next;
			continue ;
		}
		if (curr->type == TOK_FLAGS && !flag_check(curr->token))
		{
			printf("%s ", curr->token);
		}
		if (curr->type == TOK_ARGS)
			printf("%s", curr->token);
		curr = curr->next;
	}
}

int	builtin_echo(t_cmd *cmd)
{
	bool			keep_n_line;
	char			*flag;
	int				len;

	keep_n_line = true;
	if (cont_tok_by_type(&cmd->tok_head, TOK_FLAGS) > 0)
	{
		len = ft_strlen(get_tok_content_by_type(&cmd->tok_head, TOK_FLAGS));
		flag = ft_malloc(len + 1);
		ft_strcpy(flag, get_tok_content_by_type(&cmd->tok_head, TOK_FLAGS));
		if (check_echo_flag(flag) == 0)
			keep_n_line = false;
	}
	echo_print(cmd);
	if (keep_n_line)
		printf("\n");
	exit(0);
}
