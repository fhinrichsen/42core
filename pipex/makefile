NAME = pipex

# compile flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)

AR = ar rcs

RM = rm -f

# directories
SRCDIR = $(addprefix $(PIPEX_DIR), /src/)
OBJDIR = obj/

# pipex
PIPEX_DIR = ./pipex_resources

#libft
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

#colors

DEF_COLOR		=		\033[0;39m
ORANGE			=		\033[0;33m
RED				=		\033[0;91m
GREEN			=		\033[1;92m
WHITE			=		\033[0;97m

FUNCTIONS =	main \
			file_and_struct \
			errors \
			children \
			pipex_parsing 


SRCFILES = $(addprefix $(SRCDIR), $(addsuffix .c, $(FUNCTIONS)))
OBJFILES = $(addprefix $(OBJDIR), $(addsuffix .o, $(FUNCTIONS)))

.PHONY: all re clean fclean

all: $(NAME) 

$(NAME):
	@make -C ./libft
	@$(COMPILE) $(SRCFILES) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) created.$(DEF_COLOR)"


clean: 
	@make clean -C $(LIBFT_DIR)

fclean: 
	@make fclean -C $(LIBFT_DIR)
	@$(RM) pipex
	@echo "$(ORANGE)$(NAME) removed.$(DEF_COLOR)"

# test: fclean all
# 	@echo Hello hello test test test > testing.txt
# 	./pipex testing.txt "grep hello" "ls -l" test3.txt

# testclean: fclean
# 	rm *.txt

re: fclean all