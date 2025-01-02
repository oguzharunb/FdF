NAME		= libgnl.a

CFLAGS		= -Wall -Wextra -Werror
ARFLAGS 	= rcs
RM			= rm -rf

BUILD_DIR	= build
SRCS		= get_next_line.c get_next_line_utils.c
OBJS		= $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re