#include "_incl/exec.h"
//
//void	args_format(t_cmd *cmd)
//{
//	cmd->execve_args = malloc();
//
//}

char	*find_cmd_path(t_cmd *cmd)
{
	char	**path_matrix;
	char	*path;
	int		i;

	if (!access(cmd->cmd, F_OK))
		return("ok");
	i = 0;
	path_matrix = ft_split(get_content_by_name(&cmd->main_ref->env_head, "PATH"), ':');
	while (path_matrix[i])
	{
		path = complete_path( path_matrix[i], cmd);
		if (!access(path, F_OK))
		{
			ft_free_matrix(path_matrix);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_matrix(path_matrix);
	return (NULL);
}

int	exe_builtins(t_cmd *cmd)
{
	char	*tmp;

	/*			Test			*/
	tmp = malloc(ft_strlen(cmd->cmd) + 1);
	ft_strcpy(tmp, cmd->cmd);

	/*	This is the original code, the one above is just for testing
	tmp = malloc(ft_strlen(get_tok_content_by_type(&cmd->tok_head, TOK_CMD)) + 1);
	if (tmp)
		return 1;
	ft_strcpy(tmp, get_tok_content_by_type(&cmd->tok_head, TOK_CMD));
	*/

	if (!ft_strcmp("echo", tmp))
	{
		/* bin_echo(); should return 0*/
		printf("echo\n");
		return 0;
	}
	if (!ft_strcmp("cd", tmp))
	{
		/* bin_cd(); should return 0 */
		printf("cd\n");
		return 0;
	}
	if (!ft_strcmp("pwd", tmp))
	{
		/* bin_pwd(); should return 0 */
		printf("pwd\n");
		return 0;
	}
	if (!ft_strcmp("export", tmp))
	{
		/* bin_export(); should return 0 */
		printf("export\n");
		return 0;
	}
	if (!ft_strcmp("env", tmp))
	{
		/* bin_env(); should return 0 */
		printf("env\n");
		return 0;
	}
	if (!ft_strcmp("unset", tmp))
	{
		/* bin_unset(); should return 0 */
		printf("unset\n");
		return 0;
	}
	if (!ft_strcmp("exit", tmp))
	{
		/* bin_exit(); should return 0 */
		printf("exit\n");
		return 0;
	}
	free(tmp);
	return (1);
}

int	execute(t_cmd *cmd)
{
	char *path;
	if (exe_builtins(cmd))
	{
		path = find_cmd_path(cmd);
		printf("result path: %s\n", path);
		args_format();
//		execve(path, );
	}
	return (0);
}

/*				TEST				*/

void	test(t_main *main)
{
	add_cmd_last(&main->cmd_head, main, "export");
}

int main(int argc, char **argv, char **envp)
{
	t_main main;

	main.env_head = NULL;
	main.cmd_head = NULL;
	copy_env(&main.env_head, envp);
	test(&main);
	execute(main.cmd_head);
//	printf("cmd.cmd2: %s\n", main.cmd_head->cmd );
	clear_cmd_list(&main.cmd_head);
	clear_env(&main.env_head);
	return (printf("path took correctly\n"));
}
