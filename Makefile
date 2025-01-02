NAME			= fdf

INC_DIR			= inc
LIB_DIR			= lib
LIBFT_DIR		= $(LIB_DIR)/libft
GNL_DIR			= $(LIB_DIR)/get_next_line
MLX_DIR			= $(LIB_DIR)/minilibx
LIBFT			= $(LIBFT_DIR)/libft.a
GNL				= $(GNL_DIR)/libgnl.a
MLX				= $(MLX_DIR)/libmlx.a
BUILD_DIR		= build

SRCS			= fdf.c
OBJS			= $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
CFLAGS			= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR)
LDFLAGS			= -L$(LIBFT_DIR) -L$(GNL_DIR) -L$(MLX_DIR)
LDLIBS			= -lmlx -lft -lgnl -lXext -lX11 -lm

RM				= rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(GNL)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(GNL):
	@make -C $(GNL_DIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	$(RM) $(BUILD_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(GNL_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(GNL_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re