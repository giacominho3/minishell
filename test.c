#include <stdio.h>
#include "incl/minishell.h"

int main(void)
{
	int fd;

	if((fd = open("./sugma1", O_CREAT | O_WRONLY)) < 0)
		perror("no sugma :(\n");
	dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("sbrugna, smegma");
}
