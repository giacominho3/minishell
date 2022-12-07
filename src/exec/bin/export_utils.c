#include "../_incl/builtins.h"

int	ft_modded_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 != '=' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

int	is_in_export(char *arg, t_export *export)
{
	int		i;
	char	*tmp;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	tmp = ft_strndup(arg, i);
	while (export->entries[i])
	{
		if (!ft_modded_strcmp(export->entries[i], tmp))
			return (1);
		i++;
	}
	return (0);
}

int	is_in_env(char *arg, t_env **env)
{
	int		i;
	char	*tmp;
	t_env	*head;

	i = 0;
	head = (*env);
	while (arg[i] != '=')
		i++;
	tmp = ft_strndup(arg, i);
	if (!ft_modded_strcmp(get_content_by_name(&head, tmp), ""))
		return (1);
	return (0);
}

void	edit_env(char *arg, t_env **env)
{
	t_env	*curr;

	curr = (*env);
	while (curr->next)
	{
		if (!ft_modded_strcmp(curr->content, arg))
			ft_set_data(curr, arg);
		curr = curr->next;
	}
}

void	edit_export(char *arg, t_export *export, t_env **env)
{
	int		i;
	char	*tmp;

	i = 0;
	if (is_in_env(arg, env))
		edit_env(arg, env);
	while (arg[i] && arg[i] != '=')
		i++;
	tmp = ft_strndup(arg, i);
	while (export->entries[i])
	{
		if (!ft_modded_strcmp(export->entries[i], tmp))
		{
			free(export->entries[i]);
			export->entries[i] = malloc(ft_strlen(arg) + 1);
			ft_strcpy(export->entries[i], arg);
		}
		i++;
	}
}

char	**add_to_export(char *arg, t_export *export)
{
	int		i;
	char	**new_export;

	i = 0;
	while (export->entries[i])
		i++;
	new_export = (char **)malloc((i + 2) * sizeof(char *));
	i = 0;
	while (export->entries[i])
	{
		new_export[i] = malloc(ft_strlen(export->entries[i]));
		ft_strcpy(new_export[i], export->entries[i]);
		free(export->entries[i]);
		i++;
	}
	i++;
	new_export[i] = malloc(ft_strlen(arg));
	ft_strcpy(new_export[i], arg);
	free(arg);
	i++;
	new_export[i] = 0;
	free(export);
	return (new_export);
}

void	add_env_and_export(t_export *export, t_env *env)
{
	int	i;
	int	j;
	int	equals;

	i = 0;
	j = 0;
	equals = 0;
	while (export->args[i])
	{
		if (is_in_export(export->args[i], export))
			edit_export(export->args[i], export, &env);
		else
		{
			while (export->args[i][j])
			{
				if (export->args[i][j] == '=')
					equals = 1;
				j++;
			}
			if (!equals)
				ft_add_last(&env, export->args[i]);
			export->entries = add_to_export(export->args[i], export);
		}
		i++;
	}
}
