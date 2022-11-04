#include <stdio.h>
#include "incl/minishell.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = -1;
	while (*src)
	{
		dst = src;
		dst++;
		src++;
	}
}

int main(void)
{
	char *string1;

	string1 = malloc(7);
	char a = 97;
	int i = 0;
	while (a < 102)
	{
		string1[i] = a;
		i++;
		a++;
	}
	string1[i] = 0;
	char *string2 = malloc(ft_strlen(string1));
	ft_strcpy(string2, string1);
	free(string1);
	string1 = malloc(8);
	ft_strcpy(string1, string2);
	string1[5] = 'f';
	string1[6] = 'g';
	string1[7] = 'h';
	string1[8] = 'i';
	string1[9] = 'i';
	i = 0;
	while(string1[i])
	{
		printf("%c ", string1[i]);
		i++;
	}
}