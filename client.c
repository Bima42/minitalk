#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	(void)pid;
	(void)str;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
	}
	else
		printf("Put PID on argument, then a string\n");
	return (0);
}
