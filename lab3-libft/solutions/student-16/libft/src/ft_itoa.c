#include "../inc/libft.h"

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	len = num_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		num = (unsigned int)(-n);
	}
	else
		num = (unsigned int)n;
	while (len > (n < 0 ? 1 : 0))
	{
		str[--len] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}
