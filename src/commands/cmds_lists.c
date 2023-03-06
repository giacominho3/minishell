#include "../../incl/minishell.h"

void	ft_set_cmd(t_cmd *node, t_main *main, char *cmd)
{
	if (!cmd)
		return ;
	node->tok_head = NULL;
	node->cmd = ft_strdup(cmd);
	node->main_ref = main;
}

void	add_cmd_last(t_cmd **head, t_main *main, char *cmd)
{
	t_cmd	*new;
	t_cmd	*last;

	last = (*head);
	new = (t_cmd *)ft_malloc(sizeof(t_cmd));
	if (!new)
	{
		printf("add_cmd_last: error while allocating new node: cmd: (%s)\n", cmd);
		return ;
	}
	ft_set_cmd(new, main, cmd);
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

void clear_cmd_list(t_cmd **head)
{
	t_cmd	*current;
	t_cmd	*next;

	current = (*head);
	while (current != NULL)
	{
		next = current->next;
//		write(1, "a\n", 2);
		clear_tokens(&current->tok_head);
//		if (current->execve_args) {
//			printf("current->execve_args: %p\n", &current->execve_args);
//			ft_free_matrix(current->execve_args);
//		}
		if (current->cmd)
		{
//			printf("current->cmd: %p\n", &current->cmd);
			free(current->cmd);
		}
//		write(1, "c\n", 2);
//		write(1, "d\n", 2);
//		printf("current: %p\n", &current);
		free(current);
		current = next;
	}
	*head = NULL;
}

int	cont_cmd_number(t_cmd **cmd_head)
{
	t_cmd	*curr;
	int		cont;

	cont = 0;
	curr = (*cmd_head);
	while (curr != NULL)
	{
		cont++;
		curr = curr->next;
	}
	return (cont);
}
