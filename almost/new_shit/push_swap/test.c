#include <fcntl.h>
#include <stdio.h>
#include "./libft/libft.h"

int	main(void)
{
	int fd;

	fd = open("file.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	ft_putstr_fd("hello\n", fd);
	fd = open("file.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	ft_putstr_fd("world\n", fd);
	return (0);
}