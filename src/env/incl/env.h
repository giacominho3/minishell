#ifndef MINISHELL_ENV_H
# define MINISHELL_ENV_H
# include "../../../incl/minishell.h"

typedef struct	s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

void	ft_add_front(struct s_env **head, char *str);
void	ft_add_last(struct s_env **head, char *str);
void	ft_add_after(struct s_env *prev_node, char *str);
void	ft_add_before(struct s_env *next_node, char *str);
void	print_env(struct s_env **head);
void	ft_set_data(struct s_env *node, char *str);
void	copy_env(struct s_env **head, char **envp);
char	*get_content_by_name(struct s_env **head, char *name);
void	clear_env(struct s_env **head);

#endif //MINISHELL_ENV_H
