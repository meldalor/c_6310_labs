#include "txtfile.h"

int	longest_line_length(char **lines)
{
	int	max;
	int	len;
	int	i;

	if (!lines)
		return (-1);
	max = 0;
	i = 0;
	while (lines[i])
	{
		len = (int)ft_strlen(lines[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}
