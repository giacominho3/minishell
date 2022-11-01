#include "../../incl/minishell.h"

/* this function looks for the character c in the string str
 * and if it finds it returns true otherwise returns false*/
bool	find_char_instr(char c, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (true);
	}
	return (false);
}

/* not very sure if this function is actually useful or not */
char	*ft_get_command(char *str, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(ft_strlen(str));
	if (!tmp)
	{
		perror("cmds_lists.c:25:29 | ft_get_command(): could not allocate tmp\n");
		return ;
	}
	while (str[i] && str[i] != c)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

/* same as the one above */
char	*ft_get_content(char *str, char c)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)malloc(sizeof(int) * ft_strlen(str));
	if (!tmp)
		perror("env.c:55:57 | ft_get_content()");
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	i++;
	j = 0;
	while (str[i])
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	tmp[j] = 0;
	return (tmp);
}
/* I think I've to recode this whole file */
void	ft_set_data(struct s_env *node, char *str)
{
	if (!find_char_instr('=', str))
	{
		node->name = ft_get_name(str, 61);
		node->content = NULL;
		return ;
	}
	node->name = ft_get_name(str, 61);
	node->content = ft_get_content(str, 61);
}
