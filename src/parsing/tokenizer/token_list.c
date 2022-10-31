//
// Created by Tommaso Terribili on 10/31/22.
//
#include "incl/tokens.h"

/**/
void	ft_set_tok(struct s_env *node, t_tokens type, char *str)
{

}

/* add a node to the end of the list */
void	ft_add_last_tok(struct s_tok **head, t_tokens type, char *tok_val)
{
	struct s_env	*new;
	struct s_env	*last;

	last = (*head);
	new = (struct s_env *)malloc(sizeof(struct s_env));
	if (!new)
	{
		printf("add_last: error while allocating new node: str(%s)\n", str);
		return ;
	}
	ft_set_tok(new, type, tok_val);
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