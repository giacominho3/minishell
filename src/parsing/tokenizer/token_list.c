#include "incl/tokens.h"

/* this function set the values of a new node */
void	ft_set_tok(t_token_list **node, t_tokens type, char *val)
{
	int				i;
	t_token_list	*curr;

	curr = (*node);
	i = 0;
	curr->type = type;
	curr->token = (char *) malloc(ft_strlen(val) + 1);
	if (!curr->token)
	{
		perror("token_list.c:17:20 | ft_set_tok(), allocation failure\n");
		return ;
	}
	while(val[i])
	{
		curr->token[i] = val[i];
		i++;
	}
	curr->token[i] = '\0';
//	printf("___assigned_vals___\n");
//	printf("type: %u\n", curr->type);
//	printf("token: %s\n", curr->token);
}
/* this function adds a token to the end of the token list */
void	ft_add_tok_last(t_token_list **head, t_tokens type, char *tok_val)
{
	t_token_list	*new;
	t_token_list	*last;

	last = (*head);
	new = (t_token_list *)malloc(sizeof(t_token_list));
	if (!new)
	{
		printf("token_list.c:42:45 | add_tok_last: error while allocating new node: tok_val(%s)\n", tok_val);
		return ;
	}
	ft_set_tok(&new, type, tok_val);
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

/*
 * TEST MAIN FOR TOKEN LIST
int main(void)
{
	t_token_list *tokenList = NULL;
	t_token_list **head;

	ft_add_tok_last(&tokenList, TOK_CMD, "echo");
	ft_add_tok_last(&tokenList, TOK_FLAGS, "-n");
	head = &tokenList;
	printf("_______________\n");
	printf("type check, should be cmd\n");
	if ((*head)->type == TOK_CMD)
		printf("type: cmd\n");
	else
		printf("type: not cmd\n");
	(*head) = (*head)->next;
	printf("type check, should NOT be cmd\n");
	if ((*head)->type == TOK_CMD)
		printf("type: cmd\n");
	else
		printf("type: not cmd\n");
	printf("__________\n");
	printf("curr token: %s\n", (*head)->token);
	printf("__prev test__\n");
	(*head) = (*head)->prev;
	printf("prev token: %s\n", (*head)->token);
}*/
//git commit -m "token list structured, added basic funcitons to append nodes to the list"