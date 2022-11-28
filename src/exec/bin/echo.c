#include "incl/builtins.h"

int	builtin_echo(t_cmd *cmd)
{

}

bool	check_if_builtin(t_cmd *cmd)
{
	char	*tmp;

	tmp = malloc(ft_strlen(get_tok_content_by_type(cmd->tok_head, TOK_CMD)) + 1);
	ft_strcpy(tmp, get_tok_content_by_type(cmd->tok_head, TOK_CMD));
	if (strcmp("echo", tmp))
		return (true);
	if (strcmp("cd", tmp))
		return (true);
	if (strcmp("pwd", tmp))
		return (true);
	if (strcmp("export", tmp))
		return (true);
	if (strcmp("env", tmp))
		return (true);
	if (strcmp("unset", tmp))
		return (true);
	if (strcmp("exit", tmp))
		return (true);
	free(tmp);
	return (false);
}
