#include "../_incl/builtins.h"

int	builtin_pwd(t_cmd *cmd)
{
	char *tmp;

	if (cont_tok_by_type(&cmd->tok_head, TOK_FLAGS) > 0)
	{
		printf("minishell: pwd: %s: invalid option\n", get_tok_content_by_type(&cmd->tok_head, TOK_FLAGS));
		exit(EXIT_FAILURE);
	}
	tmp = get_content_by_name(&cmd->main_ref->env_head, "PWD");
	printf("%s\n", tmp);
	exit(EXIT_SUCCESS);
}
