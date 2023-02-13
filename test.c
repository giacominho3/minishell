#include <stdio.h>
#include "incl/minishell.h"

int main(int argc, char **argv, char **envp)
{
	int fd;

	if((fd = open("./as", O_RDONLY)) < 0)
		perror("no sugma :(\n");
	dup2(fd, STDIN_FILENO);
	close(fd);
	char *format[2];
	format[0] = "/bin/cat/cat";
//	format[1] = "<as";
//	format[2] = 0;
	format[1] = 0;
	if (execve("/bin/cat", format, envp) == -1)
		perror("perry\n");
//	printf("sbrugna, smegma");
}
