/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:15:58 by gifulvi          #+#    #+#             */
/*   Updated: 2022/01/20 16:32:39 by gifulvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lenght(int nb, int base)
{
	int	count;

	count = 0;
	if (nb <= 0)
		++count;
	while (nb && ++count)
		nb /= base;
	return (count);
}

char	*ft_itoa(int nb)
{
	int			len;
	char		*str;
	const char	*digits = "0123456789";

	len = lenght(nb, 10);
	str = ft_malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
		str[0] = '-';
	while (nb)
	{
		if (nb > 0)
			str[--len] = digits[nb % 10];
		else
			str[--len] = digits[nb % 10 * -1];
		nb /= 10;
	}
	return (str);
}
