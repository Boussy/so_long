/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bferdjan <bferdjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:13:26 by bferdjan          #+#    #+#             */
/*   Updated: 2025/05/20 01:23:57 by bferdjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	open_map_file(int *fd, char *filename)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		error_exit("Failed to open map file.");
}

static char	*join_content(char *content, char *buf, int bytes_read, int *total)
{
	char	*new_content;
	int		i;

	new_content = realloc(content, *total + bytes_read + 1);
	if (!new_content)
		error_exit("Realloc failed.");
	i = 0;
	while (i < bytes_read)
		new_content[(*total)++] = buf[i++];
	new_content[*total] = '\0';
	return (new_content);
}

static char	*read_map_file(char *filename)
{
	int		fd;
	char	*content;
	char	buf[1025];
	int		bytes_read;
	int		total;

	open_map_file(&fd, filename);
	content = malloc(1);
	if (!content)
		error_exit("Malloc failed.");
	content[0] = '\0';
	total = 0;
	bytes_read = read(fd, buf, 1024);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		content = join_content(content, buf, bytes_read, &total);
		bytes_read = read(fd, buf, 1024);
	}
	close(fd);
	return (content);
}

static int	get_width(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

void	parse_map(char *filename, t_game *game)
{
	char	*content;
	char	**lines;

	if (!filename || ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4))
		error_exit("Map must have .ber extension.");
	content = read_map_file(filename);
	lines = ft_split(content, '\n');
	free(content);
	if (!lines)
		error_exit("Memory allocation error in map parsing.");
	if (!lines[0])
	{
		free(lines); // Free the array when the map is empty
		error_exit("Empty or invalid map.");
	}
	game->map = lines;
	game->map_height = 0;
	game->map_width = get_width(lines[0]);
	while (lines[game->map_height])
	{
		if (get_width(lines[game->map_height]) != game->map_width)
			error_exit("Map must be rectangular.");
		game->map_height++;
	}
}
