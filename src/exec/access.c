//#include "_incl/exec.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct s_main;

typedef struct	s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef enum e_tokens
{
	TOK_CMD,
	TOK_FLAGS,
	TOK_ARGS,
	TOK_PREV_LOGIC_OP,
	TOK_NEXT_LOGIC_OP,
	TOK_IN_FILE,
	TOK_OUT_FILE,
	TOK_ERROR,
}	t_tokens;

typedef struct s_token_list
{
	t_tokens			type;
	char				*token;
	struct s_token_list	*next;
	struct s_token_list	*prev;
}	t_token_list;

typedef struct	s_cmd
{
	struct s_main	*main_ref;
	t_token_list	*tok_head;
	char			*cmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
	char			*out;
} t_cmd;

typedef struct s_main
{
	char 	*cmd_line;
	t_env	*env_head;
	t_cmd	*cmd_head;
	int		pid;
	int		exit_status;
}	t_main;


int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}



char	*ft_strdup(const char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	while (src[i])
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}



#include <stdbool.h>
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

char	*ft_get_content(char *str, char c)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)malloc(sizeof(int) * ft_strlen(str));
	if (!tmp)
		perror("env.c:55:57 | ft_get_content(), allocation failure");
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

char	*ft_get_name(char *str, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(ft_strlen(str));
	if (!tmp)
		perror("env.c:34:36 | ft_get_name(), allocation failure");
	while (str[i] && str[i] != c)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

void	ft_set_data_env(struct s_env *node, char *str)
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


void	ft_add_last(struct s_env **head, char *str)
{
	//add a node to the end of the list
	struct s_env	*new;
	struct s_env	*last;

	last = (*head);
	new = (struct s_env *)malloc(sizeof(struct s_env));
	if (!new)
	{
		printf("add_last: error while allocating new node: str(%s)\n", str);
		return ;
	}
	ft_set_data_env(new, str);
	new->next = NULL;
	if ((*head) == NULL)
	{
		new->prev = NULL;
		(*head) = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
}

void	copy_env(struct s_env **head, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		ft_add_last(head, envp[i]);
		i++;
	}
}

void	ft_set_cmd(t_cmd *node, t_main *main, char *cmd)
{
	if (!cmd)
		return ;
	node->cmd = ft_strdup(cmd);
	node->main_ref = main;
}

void	add_cmd_last(t_cmd **head, t_main *main, char *cmd)
{
	t_cmd	*new;
	t_cmd	*last;

	last = (*head);
	new = (t_cmd *) malloc(sizeof(t_cmd));
	if (!new)
	{
		printf("add_cmd_last: error while allocating new node: cmd: (%s)\n", cmd);
		return ;
	}
	ft_set_cmd(new, main, cmd);
	new->next = NULL;
	if ((*head) == NULL)
	{
		new->prev = NULL;
		(*head) = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if ((int) start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((int)len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *) malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j++] = s[i];
		}
		i++;
	}
	str[j] = 0;
	return (str);
}


static size_t	get_word(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			++ret;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (ret);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	ret = malloc(sizeof(char *) * (get_word(s, c) + 1));
	if (!ret)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	ret[i] = 0;
	return (ret);
}

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = -1;
	if (src)
	{
		while (src[++i])
			dst[i] = src[i];
		dst[i] = 0;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

char	*get_tok_content_by_type(t_token_list **head, t_tokens type)
{
	t_token_list	*curr;
	char			tmp;

	curr = (*head);
	while (curr->next != NULL)
	{
		if (curr->type == type)
			break ;
		curr = curr->next;
	}
	return (curr->token);
}

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

char	*get_content_by_name(t_env **head, char *name)
{
	struct s_env	*to_find;

	if ((*head) == NULL || name == NULL)
	{
		printf("get_content_by_name: invalid params\n");
		return (NULL);
	}
	to_find = (*head);
	while (to_find != NULL)
	{
		if (ft_strcmp(to_find->name , name) == 0)
			return (to_find->content);
		to_find = to_find->next;
	}
	return ("");
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

void clear_cmd_list(t_cmd **head)
{
	t_cmd	*current;
	t_cmd	*next;

	current = (*head);
	while (current != NULL)
	{
		free(current->cmd);
		free(current);
		current = current->next;
	}
	*head = NULL;
}


void clear_env(t_env **head)
{
	struct s_env	*current;
	struct s_env	*next;

	current = (*head);
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current->name);
		free(current);
		current = next;
	}
	(*head) = NULL;
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

char	*find_cmd_path(t_cmd *cmd)
{
	char	**path_matrix;
	char	*path;
	int		i;

	if (!access(cmd->cmd, F_OK))
		return("ok");
	i = 0;
	path_matrix = ft_split(get_content_by_name(&cmd->main_ref->env_head, "PATH"), ':');
	while (path_matrix[i])
	{
		path = complete_path( path_matrix[i], cmd);
		if (!access(path, F_OK))
		{
			ft_free_matrix(path_matrix);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_matrix(path_matrix);
	return (NULL);
}

int	exe_builtins(t_cmd *cmd)
{
	char	*tmp;

	tmp = malloc(ft_strlen(cmd->cmd) + 1);
	ft_strcpy(tmp, cmd->cmd); // test
	/*	This is the original code, the one above is just for testing
	tmp = malloc(ft_strlen(get_tok_content_by_type(&cmd->tok_head, TOK_CMD)) + 1);
	if (tmp)
		return 1;
	ft_strcpy(tmp, get_tok_content_by_type(&cmd->tok_head, TOK_CMD));
	*/
	if (!ft_strcmp("echo", tmp))
	{
		/* bin_echo(); should return 0*/
		printf("echo\n");
		return 0;
	}
	if (!ft_strcmp("cd", tmp))
	{
		/* bin_cd(); should return 0 */
		printf("cd\n");
		return 0;
	}
	if (!ft_strcmp("pwd", tmp))
	{
		/* bin_pwd(); should return 0 */
		printf("pwd\n");
		return 0;
	}
	if (!ft_strcmp("export", tmp))
	{
		/* bin_export(); should return 0 */
		printf("export\n");
		return 0;
	}
	if (!ft_strcmp("env", tmp))
	{
		/* bin_env(); should return 0 */
		printf("env\n");
		return 0;
	}
	if (!ft_strcmp("unset", tmp))
	{
		/* bin_unset(); should return 0 */
		printf("unset\n");
		return 0;
	}
	if (!ft_strcmp("exit", tmp))
	{
		/* bin_exit(); should return 0 */
		printf("exit\n");
		return 0;
	}
	free(tmp);
	return (1);
}

int execute(t_cmd *cmd)
{
	char *path;
	if (exe_builtins(cmd))
	{
		path = find_cmd_path(cmd);
		printf("result path: %s\n", path);
//		args_format();
//		execve(path, );
	}
	return 1;
}

void	test(t_main *main)
{
	add_cmd_last(&main->cmd_head, main, "export");
}

int main(int argc, char **argv, char **envp)
{
	t_main main;

	main.env_head = NULL;
	main.cmd_head = NULL;
	copy_env(&main.env_head, envp);
	test(&main);
	execute(main.cmd_head);
//	printf("cmd.cmd2: %s\n", main.cmd_head->cmd );
	clear_cmd_list(&main.cmd_head);
	clear_env(&main.env_head);
	return (printf("path took correctly\n"));
}
