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
	int lim = 0;

	i = 0;
	printf("cmd len: %d\n", ft_strlen(cmd));
	while (cmd[i] && cmd[i+1])
	{
		printf("i val beginning: %d\n", i);
		i = head_scan(cmd, i, tok_head);
		printf("i val after head: %d\n", i);
		i = body_scan(cmd, i, tok_head);
		printf("i val after body: %d (char: %c)\n", i, cmd[i]);
		i = tail_scan(cmd, i, tok_head);
		printf("i val after tail: %d (char: %c)\n", i, cmd[i]);
		lim++;
//		if (lim == 2)
//			break;
	}
	printf("tokenization termianted\n");
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
	printf("tokenizer termianted\n");
	print_token_lists(cmd_head);
	return (0);
}
