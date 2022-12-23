#include "../_incl/builtins.h"

void	update_path()
{


}

int	builtin_cd(t_cmd *cmd)
{
	char	buf[PATH_MAX];
	char	*dest;
	char	*old_pwd;

	dest = get_tok_content_by_type(&cmd->tok_head, TOK_ARGS);
	old_pwd = get_content_by_name(&cmd->main_ref->env_head, "PWD");
	if(chdir(dest) == -1)
	{
		printf("minishell: cd: directory not found\n");
		return (-1);
	}
	getcwd(buf, PATH_MAX);
	printf("buf: %s\n", buf);
	if (modify_node_content(&cmd->main_ref->env_head, "PWD", buf))
	{
		printf("minishell: cd: error while updating the PWD\n");
		return (-1);
	}
	if (modify_node_content(&cmd->main_ref->env_head, "OLDPWD", old_pwd))
	{
		printf("minishell: cd: error while updating the OLDPWD\n");
		return (-1);
	}
	return 0;
}
