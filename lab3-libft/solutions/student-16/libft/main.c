#include "inc/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void	test_chars(void)
{
	printf("=== Character functions ===\n");
	printf("ft_isalpha('a')=%d ft_isalpha('1')=%d\n", ft_isalpha('a'), ft_isalpha('1'));
	printf("ft_isdigit('5')=%d ft_isdigit('z')=%d\n", ft_isdigit('5'), ft_isdigit('z'));
	printf("ft_isalnum('a')=%d ft_isalnum('!')=%d\n", ft_isalnum('a'), ft_isalnum('!'));
	printf("ft_isascii(65)=%d ft_isascii(200)=%d\n", ft_isascii(65), ft_isascii(200));
	printf("ft_isprint(32)=%d ft_isprint(0)=%d\n", ft_isprint(32), ft_isprint(0));
	printf("ft_toupper('a')=%c ft_tolower('A')=%c\n", ft_toupper('a'), ft_tolower('A'));
	printf("ft_isspace(' ')=%d ft_isspace('a')=%d\n", ft_isspace(' '), ft_isspace('a'));
}

static void	test_strings(void)
{
	char	buf[64];

	printf("\n=== String functions ===\n");
	printf("ft_strlen(\"hello\")=%u\n", (unsigned int)ft_strlen("hello"));
	printf("ft_strchr(\"hello\",'l')=%s\n", ft_strchr("hello", 'l'));
	printf("ft_strrchr(\"hello\",'l')=%s\n", ft_strrchr("hello", 'l'));
	printf("ft_strncmp(\"abc\",\"abd\",3)=%d\n", ft_strncmp("abc", "abd", 3));
	printf("ft_strnstr(\"hello world\",\"world\",11)=%s\n", ft_strnstr("hello world", "world", 11));
	ft_strlcpy(buf, "hello", sizeof(buf));
	printf("ft_strlcpy: buf=%s\n", buf);
	ft_strlcat(buf, " world", sizeof(buf));
	printf("ft_strlcat: buf=%s\n", buf);
}

static void	test_memory(void)
{
	char	buf[10];

	printf("\n=== Memory functions ===\n");
	ft_memset(buf, 'x', 5);
	buf[5] = '\0';
	printf("ft_memset: buf=%s\n", buf);
	ft_bzero(buf, 5);
	printf("ft_bzero: buf[0]=%d\n", buf[0]);
	ft_memcpy(buf, "hello", 6);
	printf("ft_memcpy: buf=%s\n", buf);
	ft_memmove(buf + 1, buf, 4);
	printf("ft_memmove: buf=%s\n", buf);
}

static void	test_alloc(void)
{
	char	**split;
	char	*str;
	int		i;

	printf("\n=== Allocation functions ===\n");
	printf("ft_atoi(\"  -42\")=%d\n", ft_atoi("  -42"));
	str = ft_strdup("hello");
	printf("ft_strdup: %s\n", str);
	free(str);
	str = ft_substr("hello world", 6, 5);
	printf("ft_substr: %s\n", str);
	free(str);
	str = ft_strjoin("hello ", "world");
	printf("ft_strjoin: %s\n", str);
	free(str);
	str = ft_strtrim("  hello  ", " ");
	printf("ft_strtrim: %s\n", str);
	free(str);
	str = ft_itoa(-2147483648);
	printf("ft_itoa(INT_MIN): %s\n", str);
	free(str);
	split = ft_split("hello world foo", ' ');
	i = 0;
	while (split[i])
	{
		printf("ft_split[%d]: %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}

static void	del(void *content)
{
	free(content);
}

static void	*dup_str(void *content)
{
	return (ft_strdup((char *)content));
}

static void	test_lists(void)
{
	t_list	*lst;
	t_list	*mapped;

	printf("\n=== List functions ===\n");
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("first")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("second")));
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("zero")));
	printf("ft_lstsize: %d\n", ft_lstsize(lst));
	printf("ft_lstlast: %s\n", (char *)ft_lstlast(lst)->content);
	mapped = ft_lstmap(lst, dup_str, del);
	printf("ft_lstmap first: %s\n", (char *)mapped->content);
	ft_lstclear(&lst, del);
	ft_lstclear(&mapped, del);
	printf("Lists cleared OK\n");
}

int	main(void)
{
	printf("=== libft tests ===\n\n");
	test_chars();
	test_strings();
	test_memory();
	test_alloc();
	test_lists();
	printf("\n=== All tests done ===\n");
	return (0);
}
