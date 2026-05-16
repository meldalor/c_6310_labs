#include "txtfile.h"

int	count_words(char **lines)
{
	int	total;
	int	i;
	int	j;
	int	in_word;

	if (!lines)
		return (-1);
	total = 0;
	i = 0;
	while (lines[i])
	{
		j = 0;
		in_word = 0;
		while (lines[i][j])
		{
			if (!ft_isspace((unsigned char)lines[i][j]))
			{
				if (!in_word)
				{
					total++;
					in_word = 1;
				}
			}
			else
				in_word = 0;
			j++;
		}
		i++;
	}
	return (total);
}
