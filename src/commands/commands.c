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
	return (0);
}

