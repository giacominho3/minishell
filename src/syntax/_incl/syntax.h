#ifndef MINISHELL_SYNTAX_H
# define MINISHELL_SYNTAX_H
# include "../../../incl/minishell.h"

# define SYNTAX_ERR_DQUOT "Minishell: syntax error: double quotes opened but not closed\n"
# define SYNTAX_ERR_SQUOT "Minishell: syntax error: single quotes opened but not closed\n"
# define SYNTAX_ERR_INVALID_CHAR "Minishell: syntax error: invalid character\n"
# define SYNTAX_ERR_REDIR "Minishell: syntax error: invalid redirection token\n"
int		syntax_wrapper(struct s_cmd **cmd_head);
int		syntax(char *str);
bool	is_valid_syntax(char *str);
int		open_quotes_syntax(char *str, char quote);
int		open_char_syntax(char *string, char open, char close);
int		pipe_appended(char *string, char pipe);

#endif
