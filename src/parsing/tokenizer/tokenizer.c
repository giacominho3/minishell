#include "../../../incl/minishell.h"

/* I've to remove this function, it's here just for tests purpose*/
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

/* tmp, has to be removed */
int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

/* I've to move this into tokenizer utils */
void	ft_cmdcpy(char *dest, const char *src, int len, int offset)
{
	int	i;

	i = 0;
	while(src[offset] && offset < len)
	{
		dest[i] = src[offset];
		i++;
		offset++;
	}
	dest[i] = 0;
}

void	tokenizer(char *sub_string)
{
	int	i;


	i = 0;
	while (sub_string[i])
	{

	}

}


int	cmd_len(char *input, int offset)
{
	int	i;

	i = offset;
	while(input[i])
	{
		if (sep_conditions(input, i))
		{
			i += 2;
			return (i);
		}
		i++;
	}
	return (i);
}


/* command_splitter() takes in input the string read by readline and splits
 * it every time a command separator is found* creating a new node for the
 * command doubly linked list, at this point it calls the tokenizer() function
 * that proceeds to create a linked list of elements and for each element assigns
 * a value to make easier recognise the token stored in that node (example: in the
 * substring "echo $USER" the tokenizer will create a node for "echo" with the
 * token enum value for the commands and so on) */
void	command_splitter(char *input)
{
	char	*cmd;
	int 	len;
	int		i;
	int		j;

	i = 0;
	while (input[i] != 0)
	{
		cmd = (char *) malloc(cmd_len(input, i) + 1);
		if (!cmd)
		{
			perror("tokenizer.c:97:100 error while allocating cmd");
			return ;
		}
		ft_cmdcpy(cmd, input, cmd_len(input, i), i);
		printf("cmd: %s\n", cmd);
		i += cmd_len(input, i);
		tokenizer(cmd);
		free(cmd);
	}

	free(cmd);
}


int main(void)
{
	command_splitter("asdasd asdasd | sus sususus");
}
