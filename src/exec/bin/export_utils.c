#include "../_incl/builtins.h"

int	ft_modded_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 != '=' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

int	is_in_export(char *arg, t_export *export)
{
	int		i;
	char	*tmp;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	tmp = ft_strndup(arg, i);
	while (export->entries[i])
	{
		if (!ft_modded_strcmp(export->entries[i], tmp))
			return (1);
		i++;
	}
	return (0);
}

int	is_in_env(char *arg, t_env **env)
{
	int		i;
	char	*tmp;
	t_env	*head;

	i = 0;
	head = (*env);
	while (arg[i] != '=')
		i++;
	tmp = ft_strndup(arg, i);
	if (!ft_modded_strcmp(get_content_by_name(&head, tmp), ""))
		return (1);
	return (0);
}

void	edit_env(char *arg, t_env **env)
{
	t_env	*curr;

	curr = (*env);
	while (curr->next)
	{
		if (!ft_modded_strcmp(curr->content, arg))
			ft_set_data(curr, arg);
		curr = curr->next;
	}
}

void	edit_export(char *arg, t_export *export, t_env **env)
{
	int		i;
	char	*tmp;

	i = 0;
	if (is_in_env(arg, env))
		edit_env(arg, env);
	while (arg[i] && arg[i] != '=')
		i++;
	tmp = ft_strndup(arg, i);
	while (export->entries[i])
	{
		if (!ft_modded_strcmp(export->entries[i], tmp))
		{
			free(export->entries[i]);
			export->entries[i] = malloc(ft_strlen(arg) + 1);
			ft_strcpy(export->entries[i], arg);
		}
		i++;
	}
}

//add a node to the end of the list
void	ft_add_export(t_export **head, char *str)
{
	t_export	*new;
	t_export	*last;

	last = (*head);
	new = (t_export *)malloc(sizeof(t_export));
	if (!new)
	{
		printf("add_last: error while allocating new node: str(%s)\n", str);
		return ;
	}
	ft_set_data(new, str);
	new->next = NULL;
	if ((*head) == NULL)
	{
		new->prev = NULL;
		(*head) = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
}

/**
 * @brief check if the arg of a command
 * is valid to be added to the export
 */
int	check_if_valid(char *arg)
{

}

void	add_to_export(t_cmd *cmd, char *arg)
{
	if (check_if_valid(arg))
	ft_add_export(&cmd->main_ref->export_head, arg);

}


/**
 * @param cmd cmd being executed
 * @return
 *
 * @brief adds an element to the export
 */
int	add_export_element(t_cmd *cmd)
{
	t_token_list	*curr;

	curr = cmd->tok_head;
	while (curr != NULL)
	{
		if (curr->type == TOK_ARGS)
		{
			if (check_if_valid(curr->token))
			{
				printf("minishell: export: '%s': not a valid indentifier\n", curr->token);
				return (1);
			}
			add_to_export(cmd, curr->type);
		}
		curr = curr->next;
	}
	return (0);
}
