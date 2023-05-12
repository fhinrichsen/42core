NAME = push_swap

# compile flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./push_swap_rec/lib
COMPILE = $(CC) $(CFLAGS)

AR = ar rcs

RM = rm -f

# directories
SRCDIR = $(PUSH_SWAP_DIR)src/
OBJDIR = $(PUSH_SWAP_DIR)obj/

# push_swap
PUSH_SWAP_DIR = push_swap_rec/

#libft
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

#colors

DEF_COLOR		=		\033[0;39m
ORANGE			=		\033[0;33m
RED				=		\033[0;91m
GREEN			=		\033[1;92m
WHITE			=		\033[0;97m

FUNCTIONS =	main \
			stack_build \
			errors \
			validation \
			input_handling \
			stack_operations \
			node_operations \
			prison_break \
			operations_pushes \
			list_opertations \

SRCFILES = $(addprefix $(SRCDIR), $(addsuffix .c, $(FUNCTIONS)))
OBJFILES = $(addprefix $(OBJDIR), $(addsuffix .o, $(FUNCTIONS)))

.PHONY: all re clean fclean

all: $(NAME) 

fast: fclean
	@make -j $(nproc)$(NAME)

$(NAME): 
	@make -C $(LIBFT_DIR)
	@$(COMPILE) $(SRCFILES) $(LIBFT) -g -o $(NAME)
	@echo "$(GREEN)$(NAME) created.$(DEF_COLOR)"

clean:
	@$(RM) $(NAME)
	@make clean -C $(LIBFT_DIR)

fclean: 
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@echo "$(ORANGE)$(NAME) removed.$(DEF_COLOR)"

test: fast
	cd anna && ./test.sh

re: fclean all
