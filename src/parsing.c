/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:23 by cluby             #+#    #+#             */
/*   Updated: 2024/05/31 19:20:13 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Verifie que la premiere et derniere ligne soit remplie de mur (1).
void	top_bottom_walls(char *map_line, char **map_joined)
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

// Verifie si la map a bien les 2 cote oppose de la meme longueur
// un rectangle quoi.
void	check_rectangle(char *map_line, char **map_joined)
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

// Verifie les erreurs de taille de map (non rectangulaire),
// si un character n'est pas accepter dans la list, et si un
// des murs de cote n'est pas bien fermer.
// (reste du parsing fait dans pathfinding)
void	parsing_x(char *map_line, char **map_joined)
{
	int	x;

	check_rectangle(map_line, map_joined);
	x = 0;
	if (map_line[0] != '1')
		errors(WALLS_ERROR, map_joined);
	while (map_line[x])
	{
		if (map_line[x] != '0' && map_line[x] != '1' && map_line[x] != 'E' && \
			map_line[x] != 'C' && map_line[x] != 'P' && map_line[x] != 'M' && \
			map_line[x] != '\n')
			errors(BAD_CHARACTER, map_joined);
		x++;
	}
	if (map_line[x - 2] != '1')
		errors(WALLS_ERROR, map_joined);
}

// Verifie les erreurs pour la premiere et derniere ligne puis envoie
// la map ligne par ligne a parsing_x.
void	parsing_y(char **map, int linenbr)
{
	int	y;

	y = 0;
	top_bottom_walls(map[0], map);
	top_bottom_walls(map[linenbr], map);
	while (map[y])
		parsing_x(map[y++], map);
}

// Enregistre la map dans une tableau de tableau pour pouvoir
// lire ligne par ligne plus facilement et renvoi les erreur
// si besoin.
void	get_map(char **argv, t_game *game)
{
	int		fd;
	int		i;

	init_game(game);
	game->height = count_lines(argv[1]);
	ft_printf("height = %d\n", game->height);
	if (game->height == 0)
		errors(OPEN_ERROR, NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		errors(OPEN_ERROR, NULL);
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		errors(MALLOC_ERROR, NULL);
	game->map[0] = get_next_line(fd);
	i = 0;
	while (game->map[i] != NULL)
		game->map[++i] = get_next_line(fd);
	parsing_y(game->map, game->height - 1);
	pathfinding(game->map, game->height - 1);
	close(fd);
}
