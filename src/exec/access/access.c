#include "../_incl/exec.h"

char	*find_cmd_path(t_cmd *cmd)
{
	char	**path_matrix;
	char	*path;
	int		i;

	if (!access(get_tok_content_by_type(&cmd->tok_head, TOK_CMD), F_OK))
		return(get_tok_content_by_type(&cmd->tok_head, TOK_CMD));
	i = 0;
	path_matrix = ft_split(get_content_by_name(&cmd->main_ref->env_head, "PATH"), ':');
	while (path_matrix[i])
	{
		path = complete_path( path_matrix[i], cmd);
		if (!access(path, F_OK))
		{
			ft_free_matrix(path_matrix);
			printf("result path(pre return): %s\n", path);
			return (path);
		}
		printf("result path(pre return out): %s\n", path);
		free(path);
		i++;
	}
	ft_free_matrix(path_matrix);
	return (NULL);
}

int	exe_builtins(t_cmd *cmd)
{
	char	*tmp;

	tmp = malloc(ft_strlen(get_tok_content_by_type(&cmd->tok_head, TOK_CMD)) + 1);
	if (!tmp)
		return 1;
	ft_strcpy(tmp, get_tok_content_by_type(&cmd->tok_head, TOK_CMD));
	if (!ft_strcmp("echo", tmp))
		return (builtin_echo(cmd));
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
		printf("executing export builtin\n");
		return (builtin_export(cmd));
	}
	if (!ft_strcmp("env", tmp))
		return (builtin_env(cmd));
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

int	execute(t_cmd *cmd, char **env_matrix)
{
	char *path;
	if (exe_builtins(cmd))
	{
		path = find_cmd_path(cmd);
		printf("result path: %s\n", path);
		args_format(cmd, path);
		execve(path, cmd->execve_args, env_matrix);
		return (write(2, "execve error\n", 13));
	}
	return (0);
}

///*				TEST				*/
//void	test(t_main *main)
//{
//	add_cmd_last(&main->cmd_head, main, "export");
//}
//
//int main(int argc, char **argv, char **envp)
//{
//	t_main main;
//
//	main.env_head = NULL;
//	main.cmd_head = NULL;
//	copy_env(&main.env_head, envp);
//	test(&main);
//	execute(main.cmd_head);
////	printf("cmd.cmd2: %s\n", main.cmd_head->cmd );
//	clear_cmd_list(&main.cmd_head);
//	clear_env(&main.env_head);
//	return (printf("path took correctly\n"));
//}
