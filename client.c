#include "minitalk.h"

void	send_char_by_bit(unsigned char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
		{
			kill(pid, SIGUSR2);
			pause();
		}
		else
		{
			kill(pid, SIGUSR1);
			pause();
		}
		c = c >> 1;
		usleep(100);
	}
}

void	handler_client(int signal)
{
	(void)signal;
	write(1, "ok", 2);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	char	*str;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(1, "Put PID on argument, then a string\n", 35);
		exit(0);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	str = argv[2];
	sa.sa_handler = &handler_client;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);
	while (str[i])
		send_char_by_bit(str[i++], pid);
	send_char_by_bit('\n', pid);
}
