/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:16:36 by bferdjan          #+#    #+#             */
/*   Updated: 2025/04/18 01:16:00 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * game->img.size, y
		* game->img.size);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			tile = game->map[y][x];
			put_tile(game, game->img.floor, x, y);
			if (tile == '1')
				put_tile(game, game->img.wall, x, y);
			else if (tile == 'C')
				put_tile(game, game->img.item, x, y);
			else if (tile == 'E')
				put_tile(game, game->img.exit, x, y);
			else if (tile == 'P')
				put_tile(game, game->img.player, x, y);
			x++;
		}
		y++;
	}
}
