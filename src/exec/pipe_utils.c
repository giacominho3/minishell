#include "_incl/pipeline.h"

int	calc_env_y(t_env **env_head)
{
	t_env	*curr;
	int		y_cont;

	y_cont = 0;
	curr = (*env_head);
	while (curr != NULL)
	{
		y_cont++;
		curr = curr->next;
	}
	return (y_cont);
}

int	calc_env_x(t_env **env_head)
{
	t_env	*curr;
	int		max_x_cont;
	int 	curr_x_len;

	max_x_cont = 0;
	curr = (*env_head);
	while (curr != NULL)
	{
		curr_x_len = ft_strlen(curr->name) + ft_strlen(curr->content) + 1;
		if (curr_x_len > max_x_cont)
			max_x_cont = curr_x_len;
		curr = curr->next;
	}
	return (max_x_cont);
}

char	*join_name_and_cont(char *name, char *content)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = malloc(ft_strlen(name) + ft_strlen(content) + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (name[j])
	{
		tmp[i] = name[j];
		i++;
		j++;
	}
	tmp[i] = '=';
	j = 0;
	i++;
	while (content[j])
	{
		tmp[i] = content[j];
		i++;
		j++;
	}
	printf("tmp: %s\n", tmp);
	return (tmp);
}

char	**fill_env_mat(t_env **env_head)
{
	int		i;
	char	**mat;
	t_env	*curr;

	curr = (*env_head);
	mat = malloc(sizeof(char *) * (calc_env_y(env_head) + 1));
	i = 0;
	while (i < calc_env_y(env_head))
	{
		mat [i] = join_name_and_cont(curr->name, curr->content);
		curr = curr->next;
		i++;
	}
	return (mat);
}

void	args_format(t_cmd *cmd)
{
	t_token_list	*curr;
	int				i;

	cmd->execve_args = malloc(sizeof(char *) * token_list_len(&cmd->tok_head) + 1);
	curr = cmd->tok_head;
	cmd->execve_args[0] = find_cmd_path(cmd);
	i = 1;
	while (curr != NULL)
	{
		if (curr->type == TOK_CMD)
		{
			curr = curr->next;
			continue ;
		}
		cmd->execve_args[i] = get_tok_content_by_type(&cmd->tok_head, curr->type);
		curr = curr->next;
	}
}
