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

/* tmp, has to be removed */




/**
 *
 * @param sub_string = current analyzed command
 * @param head = head to the token list of the current cmd list node
 * this functions acts like a wrapper for some sub-functions that are going to
 * search for specifics types of tokens inside the command passed as a parameter
 * and returns a pointer to the head of the list of tokens for that command
 */
void	tokenizer(char *sub_string, t_token_list **head)
{
	int	offset;

	offset = 0;
	while (sub_string[offset])
	{
		offset = head_tokens();
		offset = body_tokens();
		offset = tail_tokens();
	}

}




int main(void)
{

	command_splitter("abc | defg");
}
