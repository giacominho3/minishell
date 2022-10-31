#include "../../../incl/minishell.h"
/*
void	tokenizer(char *sub_string)
{

	while()
	{

	}

}*/


bool	sep_conditions(char *str, int index) {
	if (str[index] == '|')
		return (true);
	if (str[index] == '|' && str[index + 1] == '|')
		return (true);
	if (str[index] == '&' && str[index + 1] == '&')
		return (true);
	if (str[index] == '(')
		return (true);
	if (str[index] == '[')
		return (true);
	if (str[index] == '{')
		return (true);
	if (str[index] == ';')
		return (true);
	return (false);
}

int	cmd_len(char *input, int offset)
{
	int	i;

	i = offset;
	while(input[i])
	{
		if (sep_conditions(input, i))
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

void	command_splitter(char *input)
{
	/* command_splitter() takes in input the string read by readline and splits
	 * it every time a command separator is found* creating a new node for the
	 * command doubly linked list, at this point it calls the tokenizer() function
	 * that proceeds to create a linked list of elements and for each element assigns
	 * a value to make easier recognise the token stored in that node (example: in the
	 * substring "echo $USER" the tokenizer will create a node for "echo" with the
	 * token enum value for the commands and so on)
	 * */
	char	*cmd;
	int 	len;
	int		i;

	i = 0;
	while (input[i])
	{
		printf("len: %d\n", cmd_len(input, i));
		cmd = (char *) malloc(cmd_len(input, i));
		while(input[i] && !sep_conditions())
		{

			i++;
		}
		printf("\n");
		//tokenizer(cmd);
		printf("cmd: %s\n", cmd);
		free(cmd);
	}
}

int main(void)
{
	command_splitter("asdasd asdasd | sus sususus");
}
