/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:23 by cluby             #+#    #+#             */
/*   Updated: 2024/06/12 20:28:28 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Specials cases for characters, first and last lines absolutly have to be
// filled by the character '1'.
static void	top_bottom_walls(char *map_line, char **map_joined)
{
	int	x;

	x = 0;
	if (!map_line)
		errors(WALLS_ERROR, map_joined);
	while (map_line[x])
	{
		if (map_line[x] != '1' && map_line[x] != '\n')
			errors(WALLS_ERROR, map_joined);
		x++;
	}
}

// Use the fact that a static variable is always initialized to 0 to be able
// to register the first line lenght and then compare with all the nexts ones.
// If one isn't the same length is mean the map doesn't have the good shape.
static void	check_rectangle(char *map_line, char **map_joined)
{
	int			x;
	static int	first_line;

	x = 0;
	while (map_line[x])
		x++;
	if (first_line == 0)
		first_line = x;
	if (first_line != x)
		errors(BAD_SIZE, map_joined);
}

// Check the size of each lines and if there's any non-allowed
// characters.
// Also check that the left and right walls are... well, walls
// (char '1').
static void	parsing_x(char *map_line, char **map_joined)
{
	int	x;

	check_rectangle(map_line, map_joined);
	x = 0;
	if (map_line[0] != '1')
		errors(WALLS_ERROR, map_joined);
	while (map_line[x])
	{
		if (map_line[x] != '0' && map_line[x] != '1' && map_line[x] != 'E' && \
			map_line[x] != 'C' && map_line[x] != 'P' && map_line[x] != '\n')
			errors(BAD_CHARACTER, map_joined);
		x++;
	}
	if (map_line[x - 2] != '1')
		errors(WALLS_ERROR, map_joined);
}

// Check the first and last lines since they are special cases and then check
// all the others lines to see if there is any non-allowed characters.
static void	parsing_y(char **map, int linenbr)
{
	int	y;

	y = 0;
	top_bottom_walls(map[0], map);
	top_bottom_walls(map[linenbr], map);
	while (map[y])
		parsing_x(map[y++], map);
}

// The main function that while launch the others function who, in the end
// (if the given map is valid), register the map of the game for later.
void	get_map(char **argv, t_game *game)
{
	int		fd;
	int		i;

	init_game(*game);
	game->height = count_lines(argv[1]);
	if (game->height == -1)
		errors(OPEN_ERROR, NULL);
	else if (game->height < 3)
		errors(MAP_ERROR, NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		errors(OPEN_ERROR, NULL);
	makemap(game, fd);
	game->width = ft_strlen(game->map[0]) - 1;
	parsing_y(game->map, game->height - 1);
	pathfinding(*game);
	close(fd);
}
