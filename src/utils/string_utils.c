/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:21:11 by gifulvi          #+#    #+#             */
/*   Updated: 2022/10/27 11:27:04 by gifulvi         ###   ########.fr       */
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

//bool	is_in_strings(char c, char *str)
//{
//	while (*str)
//	{
//		if (*str == c)
//			return (true);
//		str++;
//	}
//	return (false);
//}

bool	is_valid_char(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 95)
		return (true);
	else
		return (false);
}

/**
 *
 * @param dst = string into which @param src will be copied
 * @param src = string to copy inside @param dst
 * @param offset = index of @param src to start coping
 * @param stop = index of @param src to stop coping
 *
 * this function simply copy @param src from @param start to @param stop
 * inside @param dst
 */
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
	dst[i] = 0;
}
