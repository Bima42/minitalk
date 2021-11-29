#include "minitalk.h"

void	server()
{
	int pid;

	pid = getpid();
	printf("%d\n", pid);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	server();
	return (0);
}
