#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>


void	*ft_malloc(size_t size)
{
	void	*pointer;

	pointer = malloc(size);
	if (!pointer)
	{
		perror("oh fuck");
		exit (EXIT_FAILURE) ;
	}
	return (pointer);
}

int main(int argc, char* argv[], char **envp)
{
	int		*x;
	void	*address;

	x = ft_malloc(sizeof(int) * 2);
	if (!x)
	{
		perror("err");
		return 1;
	}
	printf("pointer: %p\n", &x);
	address = x;
	printf("address: %p\n", address);
	free(address);
}
