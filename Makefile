# **************************************************************************** #
#                               GNL Makefile                                   #
# **************************************************************************** #

NAME    := get_next_line.a
SRC     := get_next_line.c get_next_line_utils.c
SRC_BONUS := get_next_line_bonus.c  get_next_line_utils_bonus.c 
OBJ     := $(SRC:.c=.o)
OBJ_BONUS			:= $(SRC_BONUS: .c=.o)
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

bonus: $(NAME) $(OBJ_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

