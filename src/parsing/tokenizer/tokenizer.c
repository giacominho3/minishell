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

int	head_tokens(char *cmd, int offset, t_token_list **tok_head)
{
	scan_reidrections();
	scan_parenthesis();
}

int body_tokens(char *cmd, int offset, t_token_list **tok_head)
{

}

int tail_tokens(char *cmd, int offset, t_token_list **tok_head)
{
	scan_reidrections();
	scan_parenthesis();
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
	int	offset;

	offset = 0;
	while (cmd[offset])
	{
		offset = head_tokens(cmd, offset, tok_head);
		offset = body_tokens(cmd, offset, tok_head);
		offset = tail_tokens(cmd, offset, tok_head);
	}
}

int	tokenizer(t_cmd **cmd_head)
{
	t_cmd *curr;

	curr =  (*cmd_head);
	while (curr != NULL)
	{
		//_tokenizer(curr->cmd, &curr->tok_head);
		curr = curr->next;
	}
	return (0);
}