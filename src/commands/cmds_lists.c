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

//	if (empty_command())
//		return ;
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

/**
 *
 * @param input = string read by readline
 * command_splitter() takes in input the string read by readline and splits
 * it every time a command separator is found* creating a new node for the
 * command doubly linked list, at this point it calls the tokenizer() function
 * that proceeds to create a linked list of elements and for each element assigns
 * a value to make easier recognise the token stored in that node (example: in the
 * substring "echo $USER" the tokenizer will create a node for "echo" with the
 * token enum value for the commands and so on)
 */
