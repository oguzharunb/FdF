NAME			= fdf
BONUS_NAME		= fdf_bonus

INC_DIR			= inc
LIBFT_DIR		= libft
MLX_DIR			= minilibx
LIBFT			= $(LIBFT_DIR)/libft.a
MLX				= $(MLX_DIR)/libmlx.a
BONUS_DIR		= bonus

SRCS			= fdf.c window_management.c read_map.c libft_extra.c point_utils.c pixel_operations.c draw_line.c render_point.c window_events.c free_extra.c projectiles.c
BONUS_SRCS		= draw_line_bonus.c  fdf_bonus.c	fdf_bonus.h  free_extra_bonus.c  libft_extra_bonus.c  pixel_operations_bonus.c	point_utils_bonus.c  projectiles_bonus.c  read_map_bonus.c  render_point_bonus.c  window_bonus.h  window_events_bonus.c  window_management_bonus.c
OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(addprefix $(BONUS_DIR)/,$(BONUS_SRCS:.c=.o))
CFLAGS			= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS			= -L$(LIBFT_DIR) -L$(MLX_DIR)
LDLIBS			= -lmlx -lft -lXext -lX11 -lm

RM				= rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

bonus: $(BONUS_OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LDFLAGS) $(LDLIBS)

%o: %c
	$(CC) -g $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re