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
//			printf("result path(pre return): %s\n", path);
			return (path);
		}
//		printf("result path(pre return out): %s\n", path);
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
		builtin_cd(cmd);
		return 0;
	}
	if (!ft_strcmp("pwd", tmp))
	{
		builtin_pwd(cmd);
		return 0;
	}
	if (!ft_strcmp("export", tmp) && (token_list_len(&cmd->tok_head) == 1))
		return (export_printing(cmd));
	if (!ft_strcmp("env", tmp))
		return (builtin_env(cmd));
//	if (!ft_strcmp("unset", tmp))
//	{
//		/* bin_unset(); should return 0 */
//		printf("unset\n");
//		return 0;
//	}

	free(tmp);
	return (1);
}

void	print_mat(char **mat)
{
	int i = 0;

	if (mat[i] == NULL)
		printf("dioghane\n");
	while (mat[i])
	{
		printf("%d -> |%s|\n", i, mat[i]);
		i++;
	}
}

int	execute(t_cmd *cmd, char **env_matrix)
{
	char *path;

	if (exe_builtins(cmd))
	{
		path = find_cmd_path(cmd);
		printf("path: |%s|\n", path);
		args_format(cmd, path);
		print_mat(cmd->execve_args);
		if (execve(path, cmd->execve_args, env_matrix) == -1)
		{
			perror("Minishell");
			fprintf(stderr, "errno: %d\n", errno);
			g_exit_status = errno;
			fprintf(stderr, "g_exit: %d\n", g_exit_status);
			exit (EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}
