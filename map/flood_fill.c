/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 04:42:41 by bferdjan          #+#    #+#             */
/*   Updated: 2025/04/18 00:45:47 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'F';
		return ;
	}
	map[y][x] = 'F';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}

static char	**copy_map(char **src, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(src[i]);
		if (!copy[i])
			return (free_map(copy), NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	check_flood(char **map, t_game *g)
{
	int	x;
	int	y;

	y = -1;
	while (++y < g->map_height)
	{
		x = -1;
		while (++x < g->map_width)
		{
			if ((g->map[y][x] == 'C' || g->map[y][x] == 'E')
				&& map[y][x] != 'F')
			{
				error_exit("No valid path in map: unreachable item or exit.");
			}
		}
	}
}

void	check_valid_path(t_game *g)
{
	char	**copy;

	copy = copy_map(g->map, g->map_height);
	if (!copy)
		error_exit("Failed to copy map.");
	flood_fill(copy, g->player_y, g->player_x);
	check_flood(copy, g);
	free_map(copy);
}
