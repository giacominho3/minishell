/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:53:37 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/26 14:56:37 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	skip_intial_spaces(char *str)
{
	int	i;

	i = 0;
	while (is_in_strings(str[i], "\t\n\v\f\r "))
		i++;
	return (i);
}

int	trim_spaces(char *str, int len)
{
	int	i;

	while (is_in_strings(str[len - 1], "\t\n\v\f\r "))
		len--;
	return (len);
}

char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	while (src[i])
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
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