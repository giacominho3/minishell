/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:19:24 by tterribi          #+#    #+#             */
/*   Updated: 2022/01/19 19:19:25 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_in_string(char c, char const *str)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*buffer;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] && is_in_string(s1[j], set))
		j++;
	k = ft_strlen((char *) s1);
	while (k > j && is_in_string(s1[k - 1], set))
		k--;
	buffer = (char *) malloc(sizeof(*s1) * (k - j + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	while (j < k)
		buffer[i++] = s1[j++];
	buffer[i] = 0;
	return ((char *)buffer);
}

/**
 * @param str input string
 * @param set charset
 *
 * @brief removes all the characters in set
 * from the beginning of set
 */
char	*ft_trim_mod(char *str, char *set)
{
	char	*new;
	int		i;
	int 	h;

	if (!str)
		return (NULL);
	if (!set)
		return (str);
	i = 0;
	while (str[i] && is_in_string(str[i], set))
		i++;
	new = malloc((ft_strlen(str) - i) + 1);
	if (!new)
		return (NULL);
	h = 0;
	while(str[i])
	{
		new[h] = str[i];
		i++;
		h++;
	}
	new[h] = 0;
	return (new);
}
