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

char	*ft_strjoin(char const *s1, char const *s2)
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