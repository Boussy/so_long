/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:16:19 by bferdjan          #+#    #+#             */
/*   Updated: 2025/04/18 00:12:26 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_position(t_game *game, int new_x, int new_y)
{
	char	next_tile;

	next_tile = game->map[new_y][new_x];
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
		game->items_collected++;
	if (next_tile == 'E')
	{
		if (game->items_collected == game->items)
		{
			ft_printf("You win in %d moves!\n", game->moves + 1);
			free_all(game);
			exit(0);
		}
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

void	move_player(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_W)
		new_y--;
	else if (keycode == KEY_S)
		new_y++;
	else if (keycode == KEY_A)
		new_x--;
	else if (keycode == KEY_D)
		new_x++;
	update_position(game, new_x, new_y);
	render_map(game);
}
