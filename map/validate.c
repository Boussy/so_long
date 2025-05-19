/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:13:57 by bferdjan          #+#    #+#             */
/*   Updated: 2025/04/18 01:15:06 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_walls(t_game *game)
{
	int	i;
	int	w;

	i = 0;
	w = game->map_width - 1;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
			error_exit("Map must be surrounded by walls.");
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][w] != '1')
			error_exit("Map must be surrounded by walls.");
		i++;
	}
}

static void	count_elements(t_game *game, int *p, int *e, int *c)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				*p += 1;
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map[y][x] == 'E')
				*e += 1;
			else if (game->map[y][x] == 'C')
				*c += 1;
			else if (game->map[y][x] != '0' && game->map[y][x] != '1')
				error_exit("Invalid character in map.");
		}
	}
}

void	validate_map(t_game *game)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	check_walls(game);
	count_elements(game, &p, &e, &c);
	if (p != 1 || e != 1 || c < 1)
		error_exit("Map must contain 1 P, 1 E and at least 1 C.");
	game->items = c;
	check_valid_path(game);
}
