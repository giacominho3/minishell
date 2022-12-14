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

int	format_flags(t_cmd *cmd, t_token_list *curr_ref)
{
	int	i;
	int	n_flags;
	t_token_list *curr;

	curr = curr_ref;
	i = 1;
	n_flags = cont_tok_by_type(&curr, TOK_FLAGS);
	if (n_flags == 0)
	{
		printf("n_flags = 0\n");
		return (1);
	}
	while(n_flags > 0)
	{
		if (curr->type == TOK_FLAGS)
		{
			cmd->execve_args[i] = curr->token;
			printf("inserted flag: %s\n", curr->token);
			n_flags--;
		}
		curr = curr->next;
	}
	printf("cont_tok_by_type: %d\n", cont_tok_by_type(&curr_ref, TOK_FLAGS));
	return (cont_tok_by_type(&curr_ref, TOK_FLAGS) + 1);
}

void	args_format(t_cmd *cmd, char *path)
{
	t_token_list	*curr;
	int				i;

	printf("____ARGS FORMAT CALL____\n");
	curr = cmd->tok_head;
	i = 0;
	cmd->execve_args = malloc(sizeof(char *) * token_list_len(&curr) + 1);
	printf("token list len: %d\n", token_list_len(&curr));
	cmd->execve_args[0] = complete_path(path, cmd);
	printf("execve_args[0]: %s\n", cmd->execve_args[0]);
	if (token_list_len(&curr) == 1)
	{
		printf("porco\n");
		cmd->execve_args[1] = 0;
		return ;
	}
	printf("before: %s\n", curr->token);
	i += format_flags(cmd, curr);
	printf("i val after format flags: %d\n", i);
	printf("after: %s\n", curr->token);
	cmd->execve_args[i + 1] = 0;
	if (curr == NULL)
		printf("curr == NULL\n");
	while (curr != NULL)
	{
		if (curr->type == TOK_CMD)
		{
			printf("skipping tok cmd\n");
			curr = curr->next;
			continue ;
		}
		printf("curr->type: %d\n", curr->type);
		printf("curr->token: %s\n", curr->token);
		if (curr->type == TOK_ARGS)
		{
			cmd->execve_args[i] = get_tok_content_by_type(&curr, TOK_ARGS);
			printf("cmd->execve_args[%d]: %s\n", i, get_tok_content_by_type(&curr, TOK_ARGS));
		}
		printf("arg just cpy[%d]: %s\n", i, cmd->execve_args[i]);
		printf("arg (get_tok): %s\n", get_tok_content_by_type(&curr, TOK_ARGS));
		curr = curr->next;
		i++;
	}
	write(1, "dio\n", 4);
	cmd->execve_args[i] = 0;
//	printf("find_cmd_path: %s\n", find_cmd_path(cmd));
//	printf("cmd->execve_args[0]: %s\n", cmd->execve_args[0]);
	i = 0;
	printf("____ARGS FORMAT____\n");
	while (cmd->execve_args[i])
	{
		printf("[%d]: %s\n", i, cmd->execve_args[i]);
		i++;
	}
	printf("____________________\n");
}
