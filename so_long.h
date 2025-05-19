/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:04:32 by bferdjan          #+#    #+#             */
/*   Updated: 2025/05/20 01:23:57 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Touches */
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

/* Structures */
typedef struct s_img
{
	void	*player;
	void	*wall;
	void	*floor;
	void	*item;
	void	*exit;
	int		size;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		items;
	int		items_collected;
	int		moves;
	t_img	img;
}			t_game;

/* Fonctions principales */
void		parse_map(char *filename, t_game *game);
void		validate_map(t_game *game);
void		render_map(t_game *game);
void		move_player(int keycode, t_game *game);
void		init_game(t_game *game);
void		check_valid_path(t_game *game);
void		free_map(char **map);
void		error_exit(char *msg);

/* Fonctions utilitaires */
void		error_exit(char *msg);
void		free_map(char **map);
void		free_all(t_game *game);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(const char *s, char sep);
size_t		ft_strlen(const char *str);
int			ft_printf(const char *format, ...);
char		*ft_strdup(const char *s);
void		*ft_memset(void *s, int c, size_t n);

#endif
