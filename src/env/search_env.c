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
		if (ft_strcmp(to_find->name , name) == 0)
			return (to_find->content);
		to_find = to_find->next;
	}
	return ("");
}

void	print_env(struct s_env **head)
{
	struct s_env *tmp;

	tmp = (*head);
	while (tmp != NULL)
	{
		printf("%s=%s\n", tmp->name, tmp->content);
		tmp = tmp->next;
	}
}

/**
 * @param old_content old content of the env node
 * @param new_content new content of the env node
 *
 * @brief changes the content of an env node
 */
//char	*change_content(char *old_content, char *new_content)
//{
//	int	i;
//
//	if (old_content)
//		free(old_content);
//	old_content = malloc(ft_strlen(new_content) + 1);
//	if(!old_content)
//		return (NULL);
//	i = 0;
//	while (new_content[i])
//	{
//		old_content[i] = new_content[i];
//		i++;
//	}
//	old_content[i] = 0;
//	printf("old_content: %s\n", old_content);
//}

/**
 * @param env_head head to the env list
 * @param node_name name of the node you want to modify
 * @param new_content new content of the node
 * @returns 0 if the node is modified correctly, 1 if the node is not found, 2 if allocation fails
 *
 * @brief find a the first node corresponding to node_name and change
 * it's current content with new_content
 */
int	modify_node_content(t_env **env_head, char *node_name, char *new_content)
{
	t_env	*curr;
	int	i;

	curr = (*env_head);
	while (curr != NULL)
	{
		if (ft_strcmp(curr->name, node_name) == 0)
		{
//			printf("node content: %s\n", curr->content);
//			printf("new_content: %s\n", new_content);

			if (curr->content)
				ft_free(curr->content);
			curr->content = ft_malloc(ft_strlen(new_content) + 1);
			if(!curr->content)
				return (2);
			i = 0;
			while (new_content[i])
			{
				curr->content[i] = new_content[i];
				i++;
			}
			curr->content[i] = 0;
//			change_content(curr->content, new_content);
//			printf("updated node content: %s\n", curr->content);
			return (0);
		}
		curr = curr->next;
	}
	return (1);
}

/* this function prints a specific node (found by his name) */
//void	print_node(struct s_env **head, char *name, int print)
//{
//	struct s_env	*to_print;
//
//	to_print = find_by_name(head, name);
//	if (print == 0)
//		printf("%s", to_print->content);
//	else if (print == 1)
//		printf("%s=%s", to_print->name, to_print->content);
//}
