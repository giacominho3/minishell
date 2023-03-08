/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 07:59:54 by tterribi          #+#    #+#             */
/*   Updated: 2022/10/27 12:39:51 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

/* search the env looking for the node with a certain name, if params
* are not valid or the function doesn't find a node with the same name
* it returns NULL */
char	*get_content_by_name(struct s_env **head, char *name)
{
	struct s_env	*to_find;

	if ((*head) == NULL || name == NULL)
	{
		printf("find_by_name: invalid params\n");
		return (NULL);
	}
	to_find = (*head);
	while (to_find != NULL)
	{
		if (ft_strcmp(to_find->name, name) == 0)
			return (to_find->content);
		to_find = to_find->next;
	}
	return ("");
}

void	print_env(struct s_env **head)
{
	struct s_env	*tmp;

	tmp = (*head);
	while (tmp != NULL)
	{
		printf("%s=%s\n", tmp->name, tmp->content);
		tmp = tmp->next;
	}
}

/**
 * @param env_head head to the env list
 * @param node_name name of the node you want to modify
 * @param new_content new content of the node
 * @returns 0 if the node is modified correctly, 1 if the node is not found,
 * 2 if allocation fails
 *
 * @brief find a the first node corresponding to node_name and change
 * it's current content with new_content
 */
int	modify_node_content(t_env **env_head, char *node_name, char *new_content)
{
	t_env	*curr;
	int		i;

	curr = (*env_head);
	while (curr != NULL)
	{
		if (ft_strcmp(curr->name, node_name) == 0)
		{
			if (curr->content)
				ft_free(curr->content);
			curr->content = ft_malloc(ft_strlen(new_content) + 1);
			if (!curr->content)
				return (2);
			i = 0;
			while (new_content[i])
			{
				curr->content[i] = new_content[i];
				i++;
			}
			curr->content[i] = 0;
			return (0);
		}
		curr = curr->next;
	}
	return (1);
}
