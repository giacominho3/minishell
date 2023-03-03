#include "../../_incl/tokens.h"

int	scan_cmd(char *cmd, int i, t_token_list **tok_head)
{
	int		new_index;
	char	*tok_cpy;
	int		tok_index;

	if (cont_tok_by_type(tok_head, TOK_CMD) > 0)
		return (i);
//	printf("cmd cursor before skip: %c\n", cmd[i]);
	while (is_skippable(cmd[i]))
		i++;
//	printf("cmd cursor after skip: %c\n", cmd[i]);
	new_index = i;
	tok_index = 0;
//	printf("calc tok len: %d\n", calc_tok_len(cmd, i));
	tok_cpy = malloc(calc_tok_len(cmd, i) + 1);
	while (cmd[new_index] && !is_metacharacter(cmd[new_index])
		&& !is_skippable(cmd[new_index]))
	{
		tok_cpy[tok_index] = cmd[new_index];
		new_index++;
		tok_index++;
	}
	tok_cpy[tok_index] = 0;
	ft_add_tok_last(tok_head, TOK_CMD, tok_cpy);
//	printf("cmd tok: %s\n", tok_cpy);
	free(tok_cpy);
//	printf("new index: %d\n", new_index); //debug print
	return (new_index);
}

int	scan_flags(char *cmd, int i, t_token_list **tok_head)
{
	int		new_index;
	char	*tok_cpy;
	int		tok_index;

//	printf("SCANNING FLAGS\n");
	while (is_skippable(cmd[i])) // is_metacharacter(cmd[i]) ||
		i++;
//	printf("cursor now pointing at: %c(cmd[%d])\n", cmd[i], i);
	if (cmd[i] != 45)
		return (i);
	new_index = i;
	tok_index = 0;
	tok_cpy = malloc(calc_tok_len(cmd, i));
//	printf("calc_tok_len(flags): %d\n", calc_tok_len(cmd, i));
//	printf("new_index(flag) val: %d (on char %c)\n", new_index, cmd[new_index]);
	while (cmd[new_index] && !is_metacharacter(cmd[new_index])
		&& !is_skippable(cmd[new_index]))
	{
		tok_cpy[tok_index] = cmd[new_index];
//		printf("copied: %c in tok_cpy(flags)\n", cmd[new_index]);
		new_index++;
		tok_index++;
	}
	tok_cpy[tok_index] = 0;
	ft_add_tok_last(tok_head, TOK_FLAGS, tok_cpy);
//	printf("flag tok: %s\n", tok_cpy);
	free(tok_cpy);
	new_index = scan_flags(cmd, new_index, tok_head);
//	printf("new index: %d\n", new_index); //debug print
	return (new_index);
}

int	copy_tok(char *cmd, int new_index, int len, char *tok_cpy)
{
	int		tok_index;
	bool	s_quotes;
	bool	d_quotes;

	tok_index = 0;
	s_quotes = false;
	d_quotes = false;
	while (cmd[new_index] && tok_index < len && !is_metacharacter(cmd[new_index]))
	{

		if (cmd[new_index] == 34 && !d_quotes)
			s_quotes = !s_quotes;
		if (cmd[new_index] == 34 && !s_quotes)
			d_quotes = !d_quotes;
		if ((cmd[new_index] == 32 || cmd[new_index] == 9)
			&& (!d_quotes || !s_quotes))
			{
				new_index++;
				tok_index++;
				continue ;
			}
		tok_cpy[tok_index] = cmd[new_index];
		new_index++;
		tok_index++;
	}
	tok_cpy[tok_index] = 0;
	return (new_index);
}

int	scan_args(char *cmd, int i, t_token_list **tok_head)
{
	int		new_index;
	char	*tok_cpy;
	int		len;

	if (cmd[i] && !is_metacharacter(cmd[i]))
	{
//		printf("cursor(args) at beginning is on: %c\n", cmd[i]); //debug print
		i = skip_spaces(cmd, i);
//		printf("cursor(args) now on: %c\n", cmd[i]); //debug print
//		printf("new i val: %d\n", i); //debug print
		new_index = i;
//		printf("new_index initial value: %d\n", new_index);
//		tok_index = -1;
		len = calc_arg_len(cmd ,i);
		tok_cpy = malloc(len);
//		printf("calc_arg_len: %d\n", calc_arg_len(cmd, i));
		new_index = copy_tok(cmd, new_index, len, tok_cpy);
		ft_add_tok_last(tok_head, TOK_ARGS, tok_cpy);
//		printf("arg tok: %s\n", tok_cpy);
		free(tok_cpy);
//		printf("new index(scan args): %d\n", new_index); //debug print
		return (new_index);
	}
	return (i);
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
//		printf("new_index val before cmd scan: %d\n", new_index);
		new_index = scan_cmd(cmd, new_index, tok_head);
//		printf("new_index after cmd scan: %d\n", new_index); //debug print
		new_index = scan_flags(cmd, new_index, tok_head);
//		printf("new_index after flags scan: %d\n", new_index); //debug print
		new_index = scan_args(cmd, new_index, tok_head);
//		printf("new_index after args scan: %d\n", new_index); //debug print
	}
	return (new_index);
}
