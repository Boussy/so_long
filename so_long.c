/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:11:22 by bferdjan          #+#    #+#             */
/*   Updated: 2025/05/20 01:23:57 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game		g_game;

static int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		error_exit("Game closed.");
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		move_player(keycode, game);
	return (0);
}

static int	handle_close(t_game *game)
{
	free_all(game);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error\nUsage: ./so_long map.ber\n", 32);
		return (1);
	}
	// Initialize global game structure to zeros
	ft_memset(&g_game, 0, sizeof(t_game));
	parse_map(argv[1], &g_game);
	validate_map(&g_game);
	g_game.mlx = mlx_init();
	if (!g_game.mlx)
		error_exit("Failed to initialize MiniLibX.");
	g_game.win = mlx_new_window(g_game.mlx, g_game.map_width * 64,
			g_game.map_height * 64, "so_long");
	init_game(&g_game);
	render_map(&g_game);
	mlx_key_hook(g_game.win, handle_key, &g_game);
	mlx_hook(g_game.win, 17, 0, handle_close, &g_game);
	mlx_loop(g_game.mlx);
	return (0);
}
