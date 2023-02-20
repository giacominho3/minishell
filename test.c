#include <stdio.h>
#include "incl/minishell.h"

int main(int argc, char **argv, char **envp)
{
	int fd;

	if((fd = open("./abb", O_RDONLY)) < 0)
		perror("no sugma :(\n");
	char *format[2];
	format[0] = NULL;
//	format[1] = "<abb";
//	format[2] = 0;
	format[1] = 0;
	if (execve(NULL, format, envp) == -1)
		perror("perry\n");
//	printf("sbrugna, smegma");
}
