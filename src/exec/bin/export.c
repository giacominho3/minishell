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

void	print_export(t_export *export)
{
	int	i;

	i = 0;
	while (export->entries[i])
	{
		printf("declare -x %s\n", export->entries[i]);
		i++;
	}
}

int	builtin_export(t_cmd *cmd)
{
	t_env		*env;
	t_export	*export;
	int			i;

	write(1, "export\n", ft_strlen("export\n"));
	export = NULL;
	export->args[1] = get_tok_content_by_type(&cmd->tok_head, TOK_ARGS);
	printf("export: %s\n", export->args[1]);
	write(1, "here\n", ft_strlen("here\n"));
	env = cmd->main_ref->env_head;
	if (!export->entries[0])
		export->entries = set_export(&env);
	if (export->args[0] == 0)
		print_export(export);
	else
		add_env_and_export(export, env);
	i = 0;
	//maybe not needed
	while (export->args[i])
		free(export->args[i]);
	free(export->args);
	return (0);
}