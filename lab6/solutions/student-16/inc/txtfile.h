#ifndef TXTFILE_H
# define TXTFILE_H

# include "libft.h"

char	**read_file(const char *filename);
void	free_lines(char **lines);
void	print_lines(char **lines);

int		count_lines(char **lines);
int		count_words(char **lines);
int		count_chars(char **lines);
int		longest_line_length(char **lines);

#endif
