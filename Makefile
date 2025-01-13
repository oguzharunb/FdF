NAME			= fdf

INC_DIR			= inc
LIBFT_DIR		= libft
MLX_DIR			= minilibx
LIBFT			= $(LIBFT_DIR)/libft.a
MLX				= $(MLX_DIR)/libmlx.a

SRCS			= fdf.c window_management.c read_map.c libft_extra.c point_utils.c pixel_operations.c draw_line.c render_point.c window_events.c free_extra.c projectiles.c
OBJS			= $(SRCS:.c=.o)
CFLAGS			= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS			= -L$(LIBFT_DIR) -L$(MLX_DIR)
LDLIBS			= -lmlx -lft -lXext -lX11 -lm

RM				= rm -rf

all: $(NAME)

debug: $(OBJS) $(LIBFT) $(MLX)
	$(CC) -g $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

%o: %c
	$(CC) -g $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re