/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:08:38 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/25 19:28:26 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

int	couple_char_syntax(char *str, char c)
{
	int	i;
	int	quotes;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			quotes++;
		i++;
	}
	if ((quotes % 2) == 0)
		return (0);
	return (1);
}

int	single_quotes_syntax()
{
	
}

int	syntax(char *str)
{
	int		quotes;


}
