/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_len_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:36:42 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/25 19:36:43 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/minishell.h"

int len_var(char *str, int index)
{
	int len;
	char tmp[200];
	char *var_pointer;

	len = 0;
	tmp[0] = 0;
	while (is_valid_char(str[index]))
		tmp[len++] = str[index++];
	var_pointer = getenv(tmp);
	printf("get_env: %s\n", var_pointer);
	// add error handling for get env
	len = 0;
	while (var_pointer[len])
		len++;
	return (len);
}

int len_final(char *str)
{
	int i;
	int len;
	bool expand;

	expand = true;
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			expand = expand_manager(expand);
		if (str[i] == '$' && expand)
			len += len_var(str, i + 1);
		i++;
	}
	return (len);
}