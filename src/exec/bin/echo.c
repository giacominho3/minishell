#include "../_incl/builtins.h"

int check_echo_flag(char *flag)
{
	int i;

	i = 1;
	while (flag[i])
	{
		if (flag[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

void	echo_print(t_cmd *cmd)
{
	t_token_list	*curr;

	curr = cmd->tok_head;
	while (curr != NULL)
	{
		if (curr->type == TOK_ARGS && !strcmp("$?", curr->token))
		{
			printf("%d ", g_exit_status);
			curr = curr->next;
			continue ;
		}
		if (curr->type == TOK_FLAGS && strcmp("-n", curr->token))
			printf("%s ", curr->token);
		if (curr->type == TOK_ARGS)
			printf("%s ", curr->token);
		curr = curr->next;
	}
}

int	builtin_echo(t_cmd *cmd)
{
	bool			keep_n_line;
	char			*flag;
	int				len;

	keep_n_line = true;
	if (cont_tok_by_type(&cmd->tok_head, TOK_FLAGS) > 0)
	{
		len = ft_strlen(get_tok_content_by_type(&cmd->tok_head, TOK_FLAGS));
		flag = malloc(len + 1);
		ft_strcpy(flag, get_tok_content_by_type(&cmd->tok_head, TOK_FLAGS));
		if (check_echo_flag(flag) == 0)
			keep_n_line = false;
	}
	echo_print(cmd);
	if (keep_n_line)
		printf("\n");
	exit(0);
}

