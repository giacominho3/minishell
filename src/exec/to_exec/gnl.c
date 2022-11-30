#include <stdlib.h>
#include <unistd.h>

char *gnl(int fd)
{
	char line[99999999];
	char buf[2];
	char *str;
	int i = 0;

	line[0] = 0;
	while (read(fd, &buf[0], 1) == 0)
	{
		line[i] = buf[0];
		line[i+1] = 0;
		i++;
		if (line[i] == '\n')
			break;
	}
	line[i] = 0;
	str = malloc(i + 1);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
