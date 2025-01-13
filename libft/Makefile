COMPILER = cc
NAME = libft.a
ARCH = ar
COMPILER_FLAGS = -Wall -Werror -Wextra
ARCH_FLAGS = rcs
SRCS = ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isin.c ./ft_isprint.c ./ft_itoa.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putptr_fd.c ./ft_putstr_fd.c ./ft_split.c ./ft_strchr.c ./ft_strdup.c ./ft_strjoin.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strmapi.c ./ft_strncmp.c ./ft_strncpy.c ./ft_strrchr.c ./ft_strtrim.c ./ft_substr.c ./ft_tolower.c ./ft_upper.c ./ft_strnstr.c ./ft_striteri.c
BONUS = ./ft_lstadd_back.c ./ft_lstadd_front.c ./ft_lstclear.c ./ft_lstdelone.c ./ft_lstiter.c ./ft_lstlast.c ./ft_lstnew.c ./ft_lstprint.c ./ft_lstsize.c ./ft_lstmap.c 
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(ARCH) $(ARCH_FLAGS) $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	$(ARCH) $(ARCH_FLAGS) $(NAME) $(BONUS_OBJS)

%o: %c
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
