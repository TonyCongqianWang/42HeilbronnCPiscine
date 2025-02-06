# Define compiler and compiler flags
CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -Wall -Werror -Wextra
SRCS = main.c map_creation.c print_utils.c read_io.c\
		solve.c string_utils.c grid_coordinates.c\
		map_conversion.c structs.c
OBJS = $(SRCS:%.c=%.o)
NAME = bsq

# Default target
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)

# Clean up
clean:
	rm -rf $(OBJS)

# Force clean up
fclean: clean
	rm -rf $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re