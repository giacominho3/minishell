#include <stdio.h>
#include "incl/minishell.h"

int main(int argc, char **argv, char **envp)
{
	int fd;

	if((fd = open("./abb", O_RDONLY)) < 0)
		perror("no sugma :(\n");
	char *format[2];
	format[0] = "/bin/tmp/cat";
//	format[1] = "<abb";
//	format[2] = 0;
	format[1] = 0;
	int test = execve("/bin/tmp/cat", format, envp);
	printf("test: %d\n", test);
//	printf("sbrugna, smegma");
}
