NAME = push_swap

# compile flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)

AR = ar rcs

RM = rm -f

# directories
SRCDIR = $(addprefix $(PUSH_SWAP_DIR), /src/)
OBJDIR = obj/

# pipex
PUSH_SWAP_DIR = ./push_swap_rec

#libft
PRINTF_DIR = ./ft_printf

#colors

DEF_COLOR		=		\033[0;39m
ORANGE			=		\033[0;33m
RED				=		\033[0;91m
GREEN			=		\033[1;92m
WHITE			=		\033[0;97m

FUNCTIONS =	main \
			


SRCFILES = $(addprefix $(SRCDIR), $(addsuffix .c, $(FUNCTIONS)))
OBJFILES = $(addprefix $(OBJDIR), $(addsuffix .o, $(FUNCTIONS)))

.PHONY: all re clean fclean

all: $(NAME) 

$(NAME): 
	@make -C $(PRINTF_DIR)
	@$(COMPILE) $(SRCFILES) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) created.$(DEF_COLOR)"


clean:
	@$(RM) $(NAME)
	@make clean -C $(PRINTF_DIR)

fclean: 
	@make fclean -C $(PRINTF_DIR)
	@$(RM) $(NAME)
	@echo "$(ORANGE)$(NAME) removed.$(DEF_COLOR)"

test: fclean
	./$(TESTER_PUSH_SWAP)
	

re: fclean all
