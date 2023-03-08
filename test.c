#include "incl/minishell.h"

int main(int argc, char* argv[], char **envp)
{
	char *mat[3];

	mat[0] = "/bin/cat/cat";
	mat[1] = "abb";
	mat[2] = 0;


	execve("/bin/cat", mat, envp);
}
