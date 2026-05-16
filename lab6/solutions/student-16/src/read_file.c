#include "txtfile.h"
#include <fcntl.h>

#define BUF_SIZE 4096

static char	*read_all(int fd)
{
	char	buf[BUF_SIZE + 1];
	char	*content;
	char	*tmp;
	ssize_t	bytes;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	while (1)
	{
		bytes = read(fd, buf, BUF_SIZE);
		if (bytes < 0)
		{
			free(content);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		tmp = ft_strjoin(content, buf);
		free(content);
		if (!tmp)
			return (NULL);
		content = tmp;
	}
	return (content);
}

char	**read_file(const char *filename)
{
	int		fd;
	char	*content;
	char	**lines;

	if (!filename)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = read_all(fd);
	close(fd);
	if (!content)
		return (NULL);
	lines = ft_split(content, '\n');
	free(content);
	return (lines);
}
