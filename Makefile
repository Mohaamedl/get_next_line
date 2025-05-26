# **************************************************************************** #
#                               GNL Makefile                                   #
# **************************************************************************** #

NAME    := get_next_line.a
SRC     := get_next_line.c get_next_line_utils.c
OBJ     := $(SRC:.c=.o)
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar
ARFLAGS := rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

bonus: all

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

