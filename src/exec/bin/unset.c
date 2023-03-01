#include "../_incl/builtins.h"

void	free_export_node(t_export **export_head, t_export *node)
{
	if (*export_head == NULL || node == NULL)
		return;
	if (*export_head == node)
		*export_head = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	if (node->prev != NULL)
		node->prev->next = node->next;
	free(node);
}


void	remove_from_export(t_cmd *cmd, char *token)
{
	t_export	*tmp;

	tmp = cmd->main_ref->export_head;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->name, token))
		{
			free_export_node(&cmd->main_ref->export_head, tmp);
			break ;
		}
		tmp = tmp->next;
	}
}

int	is_in_export(t_cmd *cmd, char *find)
{
	t_export *tmp;

	tmp = cmd->main_ref->export_head;
	while(tmp != NULL)
	{
		if (!strcmp(find, tmp->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	remove_from_env(t_cmd *cmd, char *token)
{
	t_env	*tmp;

	tmp = cmd->main_ref->env_head;
	while (tmp != NULL)
	{
		if (!ft_strcmp(tmp->name, token))
		{
			free_env_node(tmp);
			break ;
		}
		tmp = tmp->next;
	}
}

void	unset(t_cmd *cmd)
{
	t_token_list *curr;

	curr = cmd->tok_head;
	while (curr != NULL)
	{
		if (curr->type == TOK_ARGS)
		{
			if (is_in_export(cmd, curr->token))
			{
				remove_from_export(cmd, curr->token);
				remove_from_env(cmd, curr->token);
			}

		}
		curr = curr->next;
	}
	g_exit_status = 0;
}
