#include "txtfile.h"

int	count_chars(char **lines)
{
	int	total;
	int	i;

	if (!lines)
		return (-1);
	total = 0;
	i = 0;
	while (lines[i])
	{
		total += (int)ft_strlen(lines[i]);
		i++;
	}
	return (total);
}
