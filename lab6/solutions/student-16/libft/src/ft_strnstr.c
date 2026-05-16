#include "../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	llen;
	size_t	i;

	if (!*little)
		return ((char *)big);
	llen = ft_strlen(little);
	i = 0;
	while (i + llen <= len && big[i])
	{
		if (ft_strncmp(big + i, little, llen) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
