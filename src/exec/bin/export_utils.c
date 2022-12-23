#include "../_incl/builtins.h"

//int	ft_modded_strcmp(char *s1, char *s2)
//{
//	while (*s1 != '\0' && *s1 != '=' && (*s1 == *s2))
//	{
//		s1++;
//		s2++;
//	}
//	return (*(char *)s1 - *(char *)s2);
//}
//
//int	is_in_export(char *arg, t_export *export)
//{
//	int		i;
//	char	*tmp;
//
//	i = 0;
//	while (arg[i] && arg[i] != '=')
//		i++;
//	tmp = ft_strndup(arg, i);
//	while (export->entries[i])
//	{
//		if (!ft_modded_strcmp(export->entries[i], tmp))
//			return (1);
//		i++;
//	}
//	return (0);
//}
//
//int	is_in_env(char *arg, t_env **env)
//{
//	int		i;
//	char	*tmp;
//	t_env	*head;
//
//	i = 0;
//	head = (*env);
//	while (arg[i] != '=')
//		i++;
//	tmp = ft_strndup(arg, i);
//	if (!ft_modded_strcmp(get_content_by_name(&head, tmp), ""))
//		return (1);
//	return (0);
//}
//
//void	edit_env(char *arg, t_env **env)
//{
//	t_env	*curr;
//
//	curr = (*env);
//	while (curr->next)
//	{
//		if (!ft_modded_strcmp(curr->content, arg))
//			ft_set_data(curr, arg);
//		curr = curr->next;
//	}
//}
//
//void	edit_export(char *arg, t_export *export, t_env **env)
//{
//	int		i;
//	char	*tmp;
//
//	i = 0;
//	if (is_in_env(arg, env))
//		edit_env(arg, env);
//	while (arg[i] && arg[i] != '=')
//		i++;
//	tmp = ft_strndup(arg, i);
//	while (export->entries[i])
//	{
//		if (!ft_modded_strcmp(export->entries[i], tmp))
//		{
//			free(export->entries[i]);
//			export->entries[i] = malloc(ft_strlen(arg) + 1);
//			ft_strcpy(export->entries[i], arg);
//		}
//		i++;
//	}
//}

void	ft_set_export_data(t_export *node, char *str)
{
	if (!find_char_instr('=', str))
	{
		node->name = str;
		printf("name added: %s\n", node->name);
		node->content = NULL;
		return ;
	}
	node->name = ft_get_name(str, 61);
	node->content = ft_get_content(str, 61);
}

/**
 * @brief add a node to the end of the export list
 */
void	ft_add_export(t_export **head, char *str)
{
	t_export	*new;
	t_export	*last;

	printf("adding: %s\n", str);
	last = (*head);
	new = (t_export *)malloc(sizeof(t_export));
	if (!new)
	{
		printf("add_last: error while allocating new node: str(%s)\n", str);
		return ;
	}
	ft_set_export_data(new, str);
	printf("new name: %s\n", new->name);
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
	printf("final: %s\n", new->name);
}

void	copy_env_to_export(t_export **head, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_add_export(head, envp[i]);
		i++;
	}
}

/**
 * @brief check if the arg of a command
 * is valid to be added to the export
 */
int	check_if_valid(char *arg)
{
	if ((arg[0] >= 65 && arg[0] <= 90)
		|| (arg[0] >= 97 && arg[0] <= 122) || arg[0] == 95)
		return (0);
	return (1);
}

/**
 * @param arg
 *
 * @brief check if the arg is valid to be added also to the env
 */
int	not_valid_for_env(char *arg)
{
	if (is_in_strings(61, arg))
		return (0);
	return (1);
}

/**
 * @param cmd ref of the cmd being executed
 * @param arg of the cmd to add to the export
 *
 * @brief adds a single arg to the export and if valid
 * also to the env
 */
void	add_to_export(t_cmd *cmd, char *arg)
{
	printf("____Adding element to export____\n");
	printf("input arg: %s\n", arg);
//	print_export(cmd);
	ft_add_export(&cmd->main_ref->export_head, arg);
	if (not_valid_for_env(arg))
		return ;
	ft_add_last(&cmd->main_ref->env_head, arg);
}

/**
 * @param cmd ref of the cmd being executed
 * @return
 *
 * @brief adds all the args of the command to the export
 */
void	add_elements_to_export(t_cmd *cmd)
{
	t_token_list	*curr;

//	printf("____export print____\n");
//	print_export(cmd);
	printf("executing test\n");
	cmd->main_ref->export_head->content = "/opt/homebrew/bin:/opt/homebrew/sbin:/Library/Frameworks/Python.framework/Versions/3.9/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/sus";
	curr = cmd->tok_head;
	while (curr != NULL)
	{
		if (curr->type == TOK_ARGS)
		{
			if (check_if_valid(curr->token))
			{
				printf("minishell: export: '%s': not a valid indentifier\n", curr->token);
				curr = curr->next;
				continue ;
			}
			add_to_export(cmd, curr->token);
		}
		curr = curr->next;
	}
	printf("__finished export exec__\n");
	print_export(cmd);
	t_export *last;

	last = cmd->main_ref->export_head;
	while(last->next != NULL)
		last = last->next;
	printf("last name: %s\n", last->name);
}
