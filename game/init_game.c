/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:15:26 by bferdjan          #+#    #+#             */
/*   Updated: 2025/05/20 01:23:57 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#define IMG_SIZE 64

static void	check_size(int w, int h, char *name)
{
	if (w != IMG_SIZE || h != IMG_SIZE)
	{
		ft_printf("Error\nInvalid size for image %s expected: 64x64\n", name);
		error_exit("Invalid image size");
	}
}

static void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img.wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &w,
			&h);
	if (!game->img.wall)
		error_exit("Failed to load image: assets/wall.xpm");
	check_size(w, h, "wall.xpm");
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &w,
			&h);
	if (!game->img.floor)
		error_exit("Failed to load image: assets/floor.xpm");
	check_size(w, h, "floor.xpm");
	game->img.item = mlx_xpm_file_to_image(game->mlx, "assets/item.xpm", &w,
			&h);
	if (!game->img.item)
		error_exit("Failed to load image: assets/item.xpm");
	check_size(w, h, "item.xpm");
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &w,
			&h);
	if (!game->img.exit)
		error_exit("Failed to load image: assets/exit.xpm");
	check_size(w, h, "exit.xpm");
	game->img.player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &w,
			&h);
	if (!game->img.player)
		error_exit("Failed to load image: assets/player.xpm");
	check_size(w, h, "player.xpm");
	game->img.size = IMG_SIZE;
}

void	init_game(t_game *game)
{
	game->items_collected = 0;
	game->moves = 0;
	load_images(game);
}
