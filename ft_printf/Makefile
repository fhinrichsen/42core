
NAME	=	libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC	=		ft_printf.c\
			ft_print_hex.c\
			utils.c\
			print_unsigned.c\
			print_pointer.c\

OUT_SRC = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OUT_SRC)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs	$(NAME)	$(OUT_SRC)

clean:
	$(RM) $(OUT_SRC)
	$(RM) */*.o
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)
	$(RM) libft/libft.a

re: fclean all clean

.PHONY: all clean fclean re