#include "../../incl/minishell.h"

/**
 * @param c = first character of a variable name
 * @return true if @pram c is considered valid ,else, false
 *
 * c can be just a letter of the alphabet so we could say that
 * c must be >= 65 && <= 90 and also >= 97 && <= 122, also '_'
 * are accepted so we c can also be == 95
 */
bool	valid_var_name(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 95)
		return (true);
	return (false);
}

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

char	*ft_strndup(char *s, size_t n)
{
	char			*str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}
