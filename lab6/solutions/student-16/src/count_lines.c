#include "txtfile.h"

int	count_lines(char **lines)
{
	int	i;

	if (!lines)
		return (-1);
	i = 0;
	while (lines[i])
		i++;
	return (i);
}
