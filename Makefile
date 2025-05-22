NAME	= so_long

SRCS	= so_long.c \
		  map/map.c \
		  map/validate.c \
		  map/flood_fill.c \
		  game/init_game.c \
		  game/move.c \
		  game/render.c \
		  utils/free.c \
		  utils/ft_mini_printf.c \
		  utils/utils.c \
		  utils/string_utils.c \
		  utils/ft_split.c

OBJS	= $(SRCS:.c=.o)

# Compilation
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I$(MLX_DIR)

# MiniLibX
MLX_DIR = minilibx-linux
MLX_INC = -I$(MLX_DIR)
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11

RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_LIB)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
