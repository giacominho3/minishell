#include "_incl/pipeline.h"

int	calc_env_y(t_env **env_head)
{
	t_env	*curr;
	int		y_cont;

	y_cont = 0;
	curr = (*env_head);
	while (curr != NULL)
	{
		curr = curr->next;
		y_cont++;
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

int	env_len(t_env **env_head)
{
	t_env	*curr;
	int cont = 0;

	curr = (*env_head);
	while (curr != NULL)
	{
		curr = curr->next;
		cont++;
	}
	return (cont);
}

char	**fill_env_mat(t_env **env_head)
{
	int		i;
	char	**mat;
	t_env	*curr;

	curr = (*env_head);
	mat = malloc(sizeof(char *) * (calc_env_y(env_head)));
	i = 0;
	while (curr != NULL)
	{
		mat[i] = join_name_and_cont(curr->name, curr->content);
		curr = curr->next;
		i++;
	}
	return (mat);
}

void	args_format(t_cmd *cmd, char *path)
{
	t_token_list	*curr;
	int				i;

	printf("____ARGS FORMAT CALL____\n");
	curr = cmd->tok_head;
	cmd->execve_args = malloc(sizeof(char *) * token_list_len(&cmd->tok_head) + 1);
	printf("token_list_len: %d\n", token_list_len(&cmd->tok_head));
	printf("path: %s\n", path);
	cmd->execve_args[0] = ft_strdup(path);
	if (token_list_len(&cmd->tok_head) == 1)
	{
		cmd->execve_args[1] = 0;
		return ;
	}
//	ft_strcpy(cmd->execve_args[0], path);
	printf("cmd->execve_args[0]: %s\n", cmd->execve_args[0]);
	i = 1;
	cmd->execve_args[i + 1] = 0;
	while (curr != NULL)
	{
		if (curr->type == TOK_CMD)
		{
			curr = curr->next;
			continue ;
		}
		cmd->execve_args[i] = get_tok_content_by_type(&cmd->tok_head, curr->type);
		printf("get_tok_content_by_type: %s\n", get_tok_content_by_type(&cmd->tok_head, curr->type));
		printf("arg just cpy[%d]: %s\n", i, cmd->execve_args[i]);
		curr = curr->next;
		i++;
	}
	cmd->execve_args[i] = 0;
	printf("find_cmd_path: %s\n", find_cmd_path(cmd));
	printf("cmd->execve_args[0]: %s\n", cmd->execve_args[0]);
	i = 0;
	printf("____ARGS FORMAT____\n");
	while (cmd->execve_args[i])
	{
		printf("[%d]: %s\n", i, cmd->execve_args[i]);
		i++;
	}
	printf("____________________\n");
}
