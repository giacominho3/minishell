#include "../_incl/tokens.h"

/**
 * @param node pointer to the node to set
 * @param type type of token that you want to assign
 * @param val string at witch assign the token type
 *
 * @brief set the values
 */
void	ft_set_tok(t_token_list **node, t_tokens type, char *val)
{
	int				i;
	t_token_list	*curr;

	curr = (*node);
	i = 0;
	curr->type = type;
	curr->token = (char *) ft_malloc(ft_strlen(val) + 1);
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
}

/**
 * @param head = head to the @struct t_token_list
 * @param type = type to assign to the @struct @param type
 * @param tok_val = token to assign to the @struct @param type
 *
 * this function adds a token to the end of the token list
 */
void	ft_add_tok_last(t_token_list **head, t_tokens type, char *tok_val)
{
	t_token_list	*new;
	t_token_list	*last;

	last = (*head);
	new = (t_token_list *)ft_malloc(sizeof(t_token_list));
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

/**
 * @param head head of the token list
 *
 * @brief deallocate all the token list
 */
void clear_tokens(t_token_list **head)
{
	t_token_list	*current;
	t_token_list	*next;

	current = (*head);
	while (current != NULL)
	{
		next = current->next;
//		printf("current->token: %p\n", &current->token);
		ft_free(current->token);
//		printf("current: %p\n", &current);
		ft_free(current);
		current = next;
	}
	(*head) = NULL;
}

/**
 * @param head head_ref to tok list
 * @param type type of tok to search
 * @return number of tokens that match the @param type
 *
 * @brief gives you the number of matching tokens inside the token list
 */
int	cont_tok_by_type(t_token_list **head, t_tokens type)
{
	int cont;
	t_token_list	*curr;

	cont = 0;
	curr = (*head);
	while (curr != NULL)
	{
		if (curr->type == type)
			cont++;
		curr = curr->next;
	}
	return (cont);
}

/**
 * @param head head to the token list contained in a command node
 * @param type type of token from the @enum t_tokens struct to look for
 * @return token if found, if not a null string
 *
 * @brief \n this function scans the t_token_list of a command to find if there's a node with
 * the type corresponding to the given type if found the
 * token if there isn't a node with the given type a null string
 */
char	*get_tok_content_by_type(t_token_list **head, t_tokens type)
{
	t_token_list	*curr;

	curr = (*head);
	while (curr->next != NULL)
	{
		if (curr->type == type)
			break ;
		curr = curr->next;
	}
	if (curr->type == type)
		return (curr->token);
	else
		return (NULL);
}

void	print_toks(t_token_list **head)
{
	t_token_list	*tmp;

	printf("___TOKS PRINT___\n");
	tmp = (*head);
	while (tmp != NULL)
	{
		printf("%s : %d (ascii val: %d)\n", tmp->token, tmp->type, tmp->token[0]);
		tmp = tmp->next;
	}
	printf("________________\n");
}

/**
 * @param head head of the command list
 *
 * @brief all the tokens lists of each command
 */
void	print_token_lists(t_cmd **head)
{
	t_cmd *tmp;
	int i = 1;

	if ((*head) == NULL)
		return ;
	tmp = (*head);
	printf("TOK_CMD: %d\n", TOK_CMD);
	printf("TOK_FLAGS: %d\n", TOK_FLAGS);
	printf("TOK_HEREDOC: %d\n", TOK_HEREDOC);
	printf("TOK_REDIRECTION: %d\n", TOK_REDIRECTION);
	printf("TOK_ARGS: %d\n", TOK_ARGS);
	printf("TOK_PREV_LOGIC_OP: %d\n", TOK_PREV_LOGIC_OP);
	printf("TOK_NEXT_LOGIC_OP: %d\n", TOK_NEXT_LOGIC_OP);
	printf("TOK_IN_FILE: %d\n", TOK_IN_FILE);
	printf("TOK_OUT_FILE: %d\n", TOK_OUT_FILE);
	printf("TOK_ERROR: %d\n", TOK_ERROR);
	while (tmp != NULL)
	{
		printf("token list of cmd %d:\n", i);
		print_toks(&tmp->tok_head);
		printf("--------------------------\n");
		tmp = tmp->next;
	}
}
