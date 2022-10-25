/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:21:11 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/25 17:59:33 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

bool	is_in_strings(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

bool	is_valid_char(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 95)
		return (true);
	else
		return (false);
}

void	ft_offset_copy(char *dst, char *src, int offset, int stop)
{
	int	i;

	if (!src && offset == 0 && stop == 0)
	{
		printf("invalid parameters\n");
		return ;
	}
	i = 0;
	while (offset < stop)
	{
		dst[i] = src[offset];
		i++;
		offset++;
	}
	dst[i] = '\0';
}
