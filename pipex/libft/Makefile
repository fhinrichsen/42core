NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)

AR = ar rcs

RM = rm -f

SRCDIR = src/
OBJDIR = obj/

#colors

DEF_COLOR		=		\033[0;39m
ORANGE			=		\033[0;33m
GRAY			=		\033[0;90m
RED				=		\033[0;91m
GREEN			=		\033[1;92m
YELLOW			=		\033[1;93m
BLUE			=		\033[0;94m
MAGENTA			=		\033[0;95m
CYAN			=		\033[0;96m
WHITE			=		\033[0;97m

FUNCTIONS =	ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isprint \
			ft_strlen \
			ft_memcpy \
			ft_memset \
			ft_bzero \
			ft_memmove \
			ft_strlcpy \
			ft_strlcat \
			ft_tolower \
			ft_toupper \
			ft_strchr \
			ft_strrchr \
			ft_strncmp \
			ft_memchr \
			ft_memcmp \
			ft_strnstr \
			ft_atoi \
			ft_calloc \
			ft_strdup \
			ft_substr \
			ft_strjoin \
			ft_strtrim \
			ft_split \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_itoa \
			ft_striteri \
			ft_strmapi

SRCFILES = $(addprefix $(SRCDIR), $(addsuffix .c, $(FUNCTIONS)))
OBJFILES = $(addprefix $(OBJDIR), $(addsuffix .o, $(FUNCTIONS)))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJFILES)
	@$(AR) $(NAME) $(OBJFILES)
	@echo "\nLibft created."

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(COMPILE) -c $< -o $@ && echo "$(GREEN)=$(DEF_COLOR)\c" | tr -d '\n'

clean:
	@$(RM) $(OBJFILES)
	@echo "$(ORANGE)Object files removed.$(DEF_COLOR)"
	@rm -rf $(OBJDIR)
	@echo "$(ORANGE)Object directory removed.$(DEF_COLOR)"
	

fclean: clean
	@$(RM) $(NAME)
	@echo "$(ORANGE)$(NAME) removed.$(DEF_COLOR)"

re: fclean all
