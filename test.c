#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[], char **envp) {
	int pid = fork();
	if (pid == -1) {
		return 1;
	}

	char *matrix[3];
	matrix[0] = "/bin/lds";
	matrix[1] = "";
	matrix[2] = 0;

	if (pid == 0) {
		int err = execve("/bin/ls", matrix, envp);
		if (err == -1) {
			printf("Could not find program to execute or other error ocurred\n");
			return 2;
		}
	} else {
		int wstatus;
		int status;

		waitpid(pid, &wstatus, WEXITSTATUS(status));
		printf("wexit: %d\n", WEXITSTATUS(status));
		printf("wexit1: %d\n", wstatus);
		if (WIFEXITED(status)) {
			int statusCode = WEXITSTATUS(status);
			if (statusCode == 0) {
				printf("Success\n");
			} else {
				printf("Failure with status code %d\n", statusCode);
			}
		}
	}

	return 0;
}
