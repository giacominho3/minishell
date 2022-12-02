#include "../../_incl/pipeline.h"

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

char	**fill_env_mat(char **mat, t_env **env_head)
{
	int		i;
//	int		j;
	int		x_alloc_val;
	t_env	*curr;

	i = 0;
	curr = (*env_head);
	mat = malloc(sizeof(char *) * (calc_env_y(env_head) + 1));
	x_alloc_val = calc_env_x(env_head);
	i = 0;
//	while (mat[i])
//	{
//		mat[i] = malloc(x_alloc_val + 1);
//		i++;
//	}
	while (i < calc_env_y(env_head))
	{
		mat [i] = join_name_and_cont(curr->name, curr->content);
		printf("join elem and cont: %s\n", mat[i]);
		i++;
	}
	//---------------------//
	printf("___fill_env_mat___\n");
	while (mat[i])
	{
		printf("mat[%d]: %s\n", i, mat[i]);
		i++;
	}
	printf("------------------\n");
	return mat;
}
