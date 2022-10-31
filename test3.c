#include <readline/readline.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
	char *buff;

	while (1)
	{
		buff = readline("fake-minishell> ");
		if(execve("./Minishell", argv, envp) == -1)
			perror("execve error\n");
		if (!buff)
			return (printf("\nfake-minishell> exit\n"));
		add_history(buff);
	}
}