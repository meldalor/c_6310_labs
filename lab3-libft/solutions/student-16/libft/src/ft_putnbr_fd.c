#include "../inc/libft.h"

static void	putnbr_unsigned(unsigned int n, int fd)
{
	if (n >= 10)
		putnbr_unsigned(n / 10, fd);
	ft_putchar_fd('0' + (n % 10), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		putnbr_unsigned((unsigned int)(-n), fd);
	}
	else
		putnbr_unsigned((unsigned int)n, fd);
}
