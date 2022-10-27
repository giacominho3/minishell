/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:30:06 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/27 12:52:01 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

bool	find_char_instr(char c, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (true);
	}
	return (false);
}

char	*ft_get_name(char *str, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(ft_strlen(str));
	if (!tmp)
		perror("dio");
	while (str[i] && str[i] != c)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

char	*ft_get_content(char *str, char c)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)malloc(sizeof(int) * ft_strlen(str));
	if (!tmp)
		perror("env.c:55:57 | ft_get_content()");
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	i++;
	j = 0;
	while (str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	tmp[j] = 0;
	return (tmp);
}

void	ft_set_data(struct s_env *node, char *str)
{
	if (!find_char_instr('=', str))
	{
		node->name = ft_get_name(str, 61);
		node->content = NULL;
		return ;
	}
	node->name = ft_get_name(str, 61);
	node->content = ft_get_content(str, 61);
}

void	copy_env(struct s_env **head, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_add_last(head, envp[i]);
		i++;
	}
}
