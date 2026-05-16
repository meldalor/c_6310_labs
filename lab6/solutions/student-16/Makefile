NAME = analyze_file
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./inc
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/read_file.c \
       $(SRC_DIR)/free_lines.c \
       $(SRC_DIR)/print_lines.c \
       $(SRC_DIR)/count_lines.c \
       $(SRC_DIR)/count_words.c \
       $(SRC_DIR)/count_chars.c \
       $(SRC_DIR)/longest_line_length.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
