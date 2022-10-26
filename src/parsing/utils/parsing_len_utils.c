/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_len_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:36:42 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/26 09:15:36 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/minishell.h"

int	len_var(char *str, int index)
{
	int len;
	char tmp[200];
	char *var_pointer;

	len = 0;
	tmp[0] = 0;
	write(1, "1\n", 2);
	while (is_valid_char(str[index]))
		tmp[len++] = str[index++];
	write(1, "2\n", 2);
	printf("len_var tmp: %s\n", tmp);
	var_pointer = getenv(tmp);
	write(1, "3\n", 2);
	// add error handling for get env
	len = 0;
	printf("len_var getenv: %s\n", var_pointer);
	write(1, "4\n", 2);
	printf ("strlen: %d\n", ft_strlen(var_pointer));
	write(1, "4\n", 2);
	while (var_pointer[len])
		len++;
	write(1, "5\n", 2);
	printf("len_var call(param=%s, getenv: %s), var len: %d\n", str, var_pointer, len);
	return (len);
}

int	len_final(char *str)
{
	int		i;
	int		len;
	bool	expand;

	printf("_____len_final call_____\n");
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
	printf("_________________________\n");
	return (len);
}