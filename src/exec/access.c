#include "_incl/exec.h"

int	exe_builtins(t_cmd *cmd)
{
	char	*tmp;

	tmp = malloc(ft_strlen(get_tok_content_by_type(&cmd->tok_head, TOK_CMD)) + 1);
	ft_strcpy(tmp, get_tok_content_by_type(&cmd->tok_head, TOK_CMD));
	if (!strcmp("echo", tmp))
		/* bin_echo(); should return 0*/
	if (!strcmp("cd", tmp))
		/* bin_cd(); should return 0 */
	if (!strcmp("pwd", tmp))
		/* bin_pwd(); should return 0 */
	if (!strcmp("export", tmp))
		/* bin_export(); should return 0 */
	if (!strcmp("env", tmp))
		/* bin_env(); should return 0 */
	if (!strcmp("unset", tmp))
		/* bin_unset(); should return 0 */
	if (!strcmp("exit", tmp))
		/* bin_exit(); should return 0 */
	free(tmp);
	return (1);
}

char *find_cmd_path(t_cmd *cmd)
{

}

int execute(t_cmd *cmd)
{
	if (exe_builtins(cmd))
	{
		find_cmd_path(cmd);
	}
}
