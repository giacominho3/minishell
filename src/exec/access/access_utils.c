/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 04:01:55 by tterribi          #+#    #+#             */
/*   Updated: 2023/03/09 04:06:25 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_incl/exec.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix || matrix == NULL)
		return ;
	while (matrix[i])
	{
		if (matrix[i])
			ft_free(matrix[i]);
		i++;
	}
	ft_free(matrix);
}

/**
 * @param path path to the TOK_CMD
 * @param cmd node of the command list
 * @return complete path to the bin for a command
 *
 * @brief takes the path given for the command in the current cmd node
 * and add the token TOK_CMD to it. example:
 * \example
 * path: /bin\n
 * cmd->TOK_CMD: cat\n
 * result: /bin/cat
 */
char	*complete_path(char *path, t_cmd *cmd)
{
	char	*dst;
	char	*tmp;
	int		i;
	int		j;

	if (!path)
		return (NULL);
	dst = ft_malloc(ft_strlen(path)
			+ ft_strlen(get_tok_content_by_type(&cmd->tok_head, TOK_CMD)) + 2);
	tmp = ft_malloc(
			ft_strlen(get_tok_content_by_type(&cmd->tok_head, TOK_CMD)) + 1);
	ft_strcpy(tmp, get_tok_content_by_type(&cmd->tok_head, TOK_CMD));
	i = -1;
	while (path[++i])
		dst[i] = path[i];
	dst[i++] = '/';
	j = 0;
	while (tmp[j])
		dst[i++] = tmp[j++];
	dst[i] = 0;
	ft_free(tmp);
	return (dst);
}
