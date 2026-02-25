###### MAMAMAKEFILE ######

# Global Config
NAME = libftprintf.a

SRC = ft_printf.c ft_what_to_print.c ft_hexa_min.c ft_double_sig.c\
ft_putchar.c ft_putnbr.c ft_putnbr_ng.c ft_putstr.c ft_hexalen.c\
get_next_line.c get_next_line_utils.c\

OBJ	= $(SRC:.c=.o)
CFLAGS	= -g -Wall -Werror -Wextra
CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $(NAME) -o $(OBJ)
	@echo "Compilation succesful"
	@echo "$(NAME) created"
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
