#include "../../incl/minishell.h"

void	ft_set_cmd(struct s_cmd *node, char *cmd)
{
	if (!cmd)
		return ;
	node->cmd = ft_strdup(cmd);
}

void	add_cmd_last(struct s_cmd **head, char *cmd)
{
	struct s_cmd	*new;
	struct s_cmd	*last;

	last = (*head);
	new = (struct s_cmd *) malloc(sizeof(struct s_cmd));
	if (!new)
	{
		printf("add_cmd_last: error while allocating new node: cmd: (%s)\n", cmd);
		return ;
	}
	ft_set_cmd(new, cmd);
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

void clear_cmd_list(struct s_cmd **head)
{
	struct s_cmd	*current;
	struct s_cmd	*next;

	current = (*head);
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
