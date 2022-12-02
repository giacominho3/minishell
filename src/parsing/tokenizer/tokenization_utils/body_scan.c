#include "../../_incl/tokens.h"

int	scan_cmd(char *cmd, int i, t_token_list **tok_head)
{
	int		new_index;
	char	*tok_cpy;
	int		tok_index;

	if (search_tok_by_type(tok_head, TOK_CMD) > 0)
		return 0;
	while (is_metacharacter(cmd[i]))
		i++;
	new_index = i;
	tok_index = 0;
	tok_cpy = malloc(calc_tok_len(cmd, i) + 1);
	while (cmd[new_index] && !is_metacharacter(cmd[new_index]))
	{
		tok_cpy[tok_index] = cmd[new_index];
		new_index++;
		tok_index++;
	}
	tok_cpy[tok_index] = 0;
	ft_add_tok_last(tok_head, TOK_CMD, tok_cpy);
	printf("new index: %d\n", new_index); //debug print
	return (new_index);
}

int	scan_flags(char *cmd, int i, t_token_list **tok_head)
{
	int		new_index;
	char	*tok_cpy;
	int		tok_index;

	while (is_metacharacter(cmd[i]))
		i++;
	if (cmd[i] != 45)
		return (0);
	new_index = i;
	tok_index = 0;
	tok_cpy = malloc(calc_tok_len(cmd, i) + 1);
	while (cmd[new_index] && !is_metacharacter(cmd[new_index]))
	{
		tok_cpy[tok_index] = cmd[new_index];
		new_index++;
		tok_index++;
	}
	tok_cpy[tok_index] = 0;
	ft_add_tok_last(tok_head, TOK_FLAGS, tok_cpy);
	printf("new index: %d\n", new_index); //debug print
	return (new_index);
}

int	scan_args(char *cmd, int i, t_token_list **tok_head)
{
	int		new_index;
	char	*tok_cpy;
	int		tok_index;

	if (cmd[i] && !is_metacharacter(cmd[i]))
	{
		printf("cursor at beginning is on: %c\n", cmd[i]); //debug print
		while (cmd[i] && is_skippable(cmd[i]))
			i++;
		printf("cursor now on: %c\n", cmd[i]); //debug print
		new_index = i;
		tok_index = 0;
		tok_cpy = malloc(calc_arg_len(cmd, i) + 1);
		while (cmd[new_index] && not_operator(cmd[new_index]))
		{
			tok_cpy[tok_index] = cmd[new_index];
			new_index++;
			tok_index++;
		}
		tok_cpy[tok_index] = 0;
		ft_add_tok_last(tok_head, TOK_ARGS, tok_cpy);
		printf("new index: %d\n", new_index); //debug print
		return (new_index);
	}
	return (0);
}

/**
 * @param cmd string to be tokenized
 * @param i index where the tokenizer is arrived
 * @param tok_head head_ref to the token list
 * @return new index where the tokenization is arrived
 *
 * @brief looks for elements that can be found in the body of a cmd line
 * for now scans just the commands, flags and args
 */
int	body_scan(char *cmd, int i, t_token_list **tok_head)
{
	int	new_index;

	new_index = i;

	if (cmd[i])
	{
		new_index += scan_cmd(cmd, new_index, tok_head);
		printf("new_index after cmd scan: %d\n", new_index); //debug print
		new_index += scan_flags(cmd, new_index, tok_head);
		printf("new_index after flags scan: %d\n", new_index); //debug print
		new_index += scan_args(cmd, new_index, tok_head);
	}
	return (new_index);
}
