#include "../../../incl/minishell.h"

/* I've to remove this function, it's here just for tests purpose*/
bool	sep_conditions(char *str, int index)
{
	if (str[index] == '|')
		return (true);
	if (str[index] == '|' && str[index + 1] == '|')
		return (true);
	if (str[index] == '&' && str[index + 1] == '&')
		return (true);
	if (str[index] == '(')
		return (true);
	if (str[index] == '[')
		return (true);
	if (str[index] == '{')
		return (true);
	if (str[index] == ';')
		return (true);
	return (false);
}

/**
 * @param sub_string = current analyzed command
 * @param head = head to the token list of the current cmd list node
 * @brief functions acts like a wrapper for some sub-functions that are going to
 * search for specifics types of tokens inside the command passed as a parameter
 * and returns a pointer to the head of the list of tokens for that command
 */
void	_tokenizer(char *cmd, t_token_list **tok_head)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		i = head_scan(cmd, i, tok_head);
		i = body_scan();
//		i = tail_scan();
	}
}

int	tokenizer(t_cmd **cmd_head)
{
	t_cmd	*curr;

	curr = (*cmd_head);
	while (curr != NULL)
	{
		_tokenizer(curr->cmd, &curr->tok_head);
		curr = curr->next;
	}
	print_token_lists(cmd_head);
	return (0);
}
