#include "../_incl/builtins.h"

int	builtin_env(t_cmd *cmd)
{
	print_env(&cmd->main_ref->env_head);
	return (0);
}