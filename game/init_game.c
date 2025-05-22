/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:15:26 by bferdjan          #+#    #+#             */
/*   Updated: 2025/05/22 04:36:30 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#define IMG_SIZE 64

static void	check_size(int w, int h, char *name)
{
	if (w != IMG_SIZE || h != IMG_SIZE)
	{
		if (ft_strncmp(name, "player.xpm", 10) == 0 && w == 32 && h == 32)
			return ;
		ft_printf("Error\nInvalid size for image %s expected: 64x64\n", name);
		error_exit("Invalid image size");
	}
}

static void	load_image(t_game *game, void **img, char *path, char *name)
{
	int	w;
	int	h;

	*img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!*img)
	{
		ft_printf("Failed to load image: %s\n", path);
		error_exit("Image loading failed");
	}
	check_size(w, h, name);
}

static void	load_images(t_game *game)
{
	load_image(game, &game->img.wall, "assets/wall.xpm", "wall.xpm");
	load_image(game, &game->img.floor, "assets/floor.xpm", "floor.xpm");
	load_image(game, &game->img.item, "assets/item.xpm", "item.xpm");
	load_image(game, &game->img.exit, "assets/exit.xpm", "exit.xpm");
	load_image(game, &game->img.player, "assets/player.xpm", "player.xpm");
	game->img.size = IMG_SIZE;
}

void	init_game(t_game *game)
{
	game->items_collected = 0;
	game->moves = 0;
	load_images(game);
}
