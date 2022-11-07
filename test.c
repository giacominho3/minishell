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
	int user = ft_strlen("tterribi ");
	int less = ft_strlen("-R ");
	int login = ft_strlen("1 ");
	int shell = ft_strlen("/bin/zsh ");
	int string = ft_strlen("a ");
	int pager = ft_strlen("less");
	printf("intial len:%d\n", ft_strlen("$USER $LESS $LOGIN_SHELL $SHELL"));
	printf("USER: %d\n", user);
	printf("LESS: %d\n", less);
	printf("LOGIN_SHELL: %d\n", login);
	printf("SHELL: %d\n", shell);
	printf("string: %d\n", string);
	printf("PAGER: %d\n", pager);

	printf("total len: %d\n", (user + less + login + shell + string));

}