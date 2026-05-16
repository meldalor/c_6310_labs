#include "txtfile.h"

int	main(int argc, char **argv)
{
	char	**lines;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./analyze_file <filename>", 2);
		return (1);
	}
	lines = read_file(argv[1]);
	if (!lines)
	{
		ft_putendl_fd("Error: cannot read file", 2);
		return (1);
	}
	ft_putstr_fd("Lines:   ", 1);
	ft_putnbr_fd(count_lines(lines), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Words:   ", 1);
	ft_putnbr_fd(count_words(lines), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Chars:   ", 1);
	ft_putnbr_fd(count_chars(lines), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Longest: ", 1);
	ft_putnbr_fd(longest_line_length(lines), 1);
	ft_putchar_fd('\n', 1);
	free_lines(lines);
	return (0);
}
