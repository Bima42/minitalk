CC	= gcc -Wextra -Wall -Werror

all	:
	$(CC) server.c libft/libft.a -o serv
	$(CC) client.c libft/libft.a -o client