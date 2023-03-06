/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:53:37 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/27 11:36:51 by tterribi         ###   ########.fr       */
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
		new[j] =str[j];
		j++;
	}
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
	ptr[i] = '\0';
	return (ptr);
}

//char	*ft_strjoin(char const *s1, char const *s2)
//{
//	int		i;
//	int		j;
//	char	*str;
//
//	i = 0;
//	j = 0;
//	if (!s1 || !s2)
//		return (NULL);
//	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
//	if (str == NULL)
//		return (NULL);
//	while (s1[i])
//		str[j++] = s1[i++];
//	i = 0;
//	while (s2[i])
//	{
//		str[j] = s2[i];
//		i++;
//		j++;
//	}
//	str[j] = '\0';
//	return (str);
//}

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
