/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:19:08 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/25 19:54:28 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/minishell.h"

bool	sep_conditions(char *str, int index)
{
	if (str[index] == '|' && str[index + 1] == '|')
		return (true);
	if (str[index] == '&' && str[index + 1] == '&')
		return (true);
	if (str[index] == '|')
		return (true);
	return (false);
}

int	logic_skip(char *str, int index)
{
	if (str[index] == '|' && str[index + 1] == '|')
		return (2);
	if (str[index] == '&' && str[index + 1] == '&')
		return (2);
	if (str[index] == '|')
		return (1);
	return (0);
}

//void	format_matrix(t_command *cmds)
//{
//	int		i;
//	int		j;
//	int		h;
//	int		stop;
//	char	*tmp;
//
//	i = 0;
//	tmp = malloc(cmds->mat_x + 1);
//	if (!tmp)
//		return ;
//	while (cmds->commands[i])
//	{
//		h = 0;
//		j = skip_intial_spaces(cmds->commands[i]);
//		stop = trim_spaces(cmds->commands[i], ft_strlen(cmds->commands[i]));
//		ft_offset_copy(cmds->commands[i], cmds->commands[i], j, stop);
//		i++;
//	}
//	free(tmp);
//}

//void	command_separator(char *str, t_command *cmds)
//{
//	int	i;
//	int	j;
//	int	h;
//
//	j = 0;
//	i = 0;
//	h = 0;
//	matrix_alloc_wrapper(str, cmds);
//	while (str[i])
//	{
//		if (sep_conditions(str, i))
//		{
//			i += logic_skip(str, i);
//			h = 0;
//			j++;
//			continue ;
//		}
//		cmds->commands[j][h] = str[i];
//		i++;
//		h++;
//	}
//	format_matrix(cmds);
//}

// int	main()
// {
// 	t_command	cmds;
// 	int			i;

// 	command_separator("scemo || culo sporco        || legge", &cmds);
// 	while (cmds.commands[i])
// 	{
// 		printf("mat[%d]: %s\n", i, cmds.commands[i]);
// 		i++;
// 	}
// }