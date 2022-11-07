#include "incl/commands.h"

/**
 * @brief debug function
 */
void	print_cmd(struct s_cmd **head)
{
	//prints the whole linked list
	struct s_cmd	*tmp;

	tmp = (*head);
	while (tmp != NULL)
	{
		printf("%s\n", tmp->cmd);
		tmp = tmp->next;
	}
}

/**
 * @brief syntax checks wrapper for commands
 */
int	syntax_wrapper(struct s_cmd **cmd_head)
{
	struct s_cmd *tmp;
	char			*buff;

	tmp = (*cmd_head);
	printf("starting node: %s\n", tmp->cmd);
	printf("second node: %s\n", tmp->next->cmd);
	while(tmp->next)
	{
		sleep(1);
		printf("passing> %s <to syntax checker\n", tmp->cmd);
		if (syntax(tmp->cmd))
			return (1);
		tmp = tmp->next;
		usleep(100);
	}
	return (0);
}

/**
 *
 * @param input string read by readline
 * @param main main struct
 *
 * @brief take the input from readline and split it in commands inside
 * the t_cmd list and then checks the syntax of each command
 */
int	command_splitter(char *input, t_main *main)
{
	char	*cmd;
	int		i;

	i = 0;
	while (input[i] != 0)
	{
		cmd = (char *)malloc(cmd_len(input, i) + 1);
		if (!cmd)
		{
			perror("tokenizer.c:97:100 error while allocating cmd");
			return (1);
		}
		ft_cmdcpy(cmd, input, cmd_len(input, i), i);
		i += cmd_len(input, i);
		add_cmd_last(&main->cmd_head, cmd);
		free(cmd);
	}
	printf("commands:\n");
	print_cmd(&main->cmd_head);
	printf("syntax:\n");
	if (syntax_wrapper(&main->cmd_head))
		return (1);
	return (0);
}
