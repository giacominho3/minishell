# include "../_incl/exec.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
//	printf("here matrix[%d]: %s\n", i, matrix[i]);
//	write(1, "crash\n", 6);
	while (matrix[i])
	{
//		write(1, "crash1\n", 7);
		if (matrix[i]) {
//			printf("matrix[%d]: %p\n", i, &matrix[i]);
			free(matrix[i]);
		}
		i++;
	}
	if (matrix) {
//		printf("matrix: %p\n", &matrix);
		free(matrix);
	}
}

/**
 * @param path path to the TOK_CMD
 * @param cmd node of the command list
 * @return complete path to the bin for a command
 *
 * @brief takes the path given for the command in the current cmd node
 * and add the token TOK_CMD to it. example:
 * \example
 * path: /bin\n
 * cmd->TOK_CMD: cat\n
 * result: /bin/cat
 */
char	*complete_path(char *path, t_cmd *cmd)
{
	char	*dst;
	char	*tmp;
	int		i;
	int		j;

	if (!path)
		return (NULL);
	dst = malloc(ft_strlen(path) + ft_strlen(get_tok_content_by_type(&cmd->tok_head, TOK_CMD)) + 2);
	tmp = malloc(ft_strlen(get_tok_content_by_type(&cmd->tok_head, TOK_CMD)) + 1);
	ft_strcpy(tmp, get_tok_content_by_type(&cmd->tok_head, TOK_CMD));
	if (!tmp || !dst)
		return (NULL);
	i = -1;
	while (path[++i])
		dst[i] = path[i];
	dst[i++] = '/';
	j = 0;
	while (tmp[j])
	{
		dst[i] = tmp[j];
		i++;
		j++;
	}
	dst[i] = 0;
	free(tmp);
	return (dst);
}
