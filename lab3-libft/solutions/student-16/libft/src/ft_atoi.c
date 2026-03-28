#include "../inc/libft.h"
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		if (result * sign > INT_MAX)
			return (INT_MAX);
		if (result * sign < INT_MIN)
			return (INT_MIN);
		nptr++;
	}
	return ((int)(result * sign));
}
