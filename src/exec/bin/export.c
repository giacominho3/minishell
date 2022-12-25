#include "../_incl/builtins.h"

void	print_export(t_cmd *cmd)
{
	t_export	*curr;

	curr = cmd->main_ref->export_head;
	while (curr != NULL)
	{
		printf("declare -x %s", curr->name);
		if (curr->content != NULL)
			printf("=\"%s\"", curr->content);
		printf("\n");
		curr = curr->next;
	}
}

int	builtin_export(t_cmd *cmd)
{
	if (token_list_len(&cmd->tok_head) == 1)
	{
		print_export(cmd);
		return 0;
	}
	add_elements_to_export(cmd);
	return 0;
}
