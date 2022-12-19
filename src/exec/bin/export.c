#include "../_incl/builtins.h"

char	**set_export(t_env **env)
{
	int		i;
	char	**export;

	i = 0;
	while (env[i])
		i++;
	export = (char **)malloc((i + 1) * sizeof(char *));
	i = 0;
	while (env[i])
	{
		export[i] = env[i]->content;
		i++;
	}
	export[i] = 0;
	return (export);
}

//int	builtin_export(t_cmd *cmd)
//{
//	t_env		*env;
//	t_export	*export;
//	int			i;
//
//	write(1, "export\n", ft_strlen("export\n"));
//	export = NULL;
//	export->args[1] = get_tok_content_by_type(&cmd->tok_head, TOK_ARGS);
//	printf("export: %s\n", export->args[1]);
//	write(1, "here\n", ft_strlen("here\n"));
//	env = cmd->main_ref->env_head;
//	if (!export->entries[0])
//		export->entries = set_export(&env);
//	if (export->args[0] == 0)
//		print_export(export);
//	else
//		add_env_and_export(export, env);
//	i = 0;
//	//maybe not needed
//	while (export->args[i])
//		free(export->args[i]);
//	free(export->args);
//	return (0);
//}
//



void	print_export(t_cmd *cmd)
{
	t_export	*curr;

	curr = cmd->main_ref->export_head;
	while (curr != NULL)
	{
		printf("declare -x %s=\"%s\"", curr->name, curr->content);
		curr = curr->next;
	}
}


int	builtin_export(t_cmd *cmd)
{
	if (token_list_len(&cmd->tok_head) == 1)
	{
		print_export(cmd);
		exit(EXIT_SUCCESS);
	}
	if (add_export_element(cmd))
	exit(EXIT_SUCCESS);
}
