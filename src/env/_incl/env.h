#ifndef MINISHELL_ENV_H
# define MINISHELL_ENV_H
# include "../../../incl/minishell.h"

/**
 * add functions
 */
void	ft_add_front(struct s_env **head, char *str);
void	ft_add_last(struct s_env **head, char *str);
void	ft_add_after(struct s_env *prev_node, char *str);
void	ft_add_before(struct s_env *next_node, char *str);

/**
 * general functions
 */
void	print_env(struct s_env **head);
void	copy_env(struct s_env **head, char **envp);
void	clear_env(struct s_env **head);

/**
 * tokenization_utils functions
 */
bool	find_char_instr(char c, char *str);
void	ft_set_data(struct s_env *node, char *str);
char	*get_content_by_name(struct s_env **head, char *name);
char	*ft_get_content(char *str, char c);
char	*ft_get_name(char *str, char c);

#endif
