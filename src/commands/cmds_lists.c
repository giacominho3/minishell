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
	struct s_cmd	*new;
	struct s_cmd	*last;

	last = (*head);
	new = (struct s_cmd *) malloc(sizeof(struct s_cmd));
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
		write(1, "a\n", 2);
		if (current->cmd)
			free(current->cmd);
		write(1, "b\n", 2);
		if (current->out != NULL) //for some reasons this cause:  malloc: *** error for object 0xf000000000000000: pointer being freed was not allocated
			free(current->out);
		write(1, "c\n", 2);
		clear_tokens(&current->tok_head);
		write(1, "d\n", 2);
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
