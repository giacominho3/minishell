#include "../_incl/tokens.h"

/**
 *
 * @param tok_head head to the token list of a command
 * @return length of the token list
 *
 * @brief calculates the number of tokens inside the list
 */
int	token_list_len(t_token_list **tok_head)
{
	t_token_list	*curr;
	int	cont;

	curr = (*tok_head);
	cont = 0;
	while (curr != NULL)
	{
		cont++;
		curr = curr->next;
	}
	return (cont);
}

