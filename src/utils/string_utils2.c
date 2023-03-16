/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:53:37 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/13 02:51:32 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

/**
 * @param str
 *
 * @brief gives the number of spaces to skip for the first char
 */
int	skip_intial_spaces(char *str)
{
	int	i;

	i = 0;
	while (is_in_strings(str[i], SPACE_CHARS))
		i++;
	return (i);
}

int	trim_spaces(char *str, int len)
{
	while (is_in_strings(str[len - 1], SPACE_CHARS))
		len--;
	return (len);
}

char	*trim_trailing_spaces(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (str[i] && is_skippable(str[i]))
		i++;
	new = ft_malloc(i + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new[j] = str[j];
		j++;
	}
	new[j] = 0;
	ft_free(str);
	return (new);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	while (src[i])
		i++;
	ptr = ft_malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = -1;
	if (src)
	{
		while (src[++i])
			dst[i] = src[i];
		dst[i] = 0;
	}
}
