# include "_incl/exec.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	*complete_path(char *src, t_cmd *cmd)
{
	char	*dst;
	int		i;
	int		j;

	dst = malloc(ft_strlen(src) + ft_strlen(cmd->cmd) + 2);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i++] = '/';
	j = 0;
	while (cmd->cmd[j])
	{
		dst[i] = cmd->cmd[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (dst);
}
