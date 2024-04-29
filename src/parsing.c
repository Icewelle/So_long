/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:23 by cluby             #+#    #+#             */
/*   Updated: 2024/04/29 06:08:13 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Verifie que la premiere et derniere ligne soit remplie de mur (1).
int	top_bottom_walls(char *map_line)
{
	int	x;

	x = 0;
	while (map_line[x])
	{
		if (map_line[x] != '1' && map_line[x] != '\n')
			return (WALLS_ERROR);
		x++;
	}
	return (NO_ERROR);
}

// Verifie si la map a bien les 2 cote oppose de la meme longueur
// un rectangle quoi.
int	check_rectangle(char *map_line)
{
	int			x;
	static int	first_line;

	x = 0;
	while (map_line[x])
		x++;
	if (first_line == 0)
		first_line = x;
	if (first_line != x)
		return (BAD_SIZE);
	return (NO_ERROR);
}

// Verifie les erreurs de taille de map (non rectangulaire),
// si un character n'est pas accepter dans la list, et si un
// des murs de cote n'est pas bien fermer.
// (reste du parsing fait dans pathfinding)
int	parsing_x(char *map_line)
{
	int	x;
	int	is_rectangle;

	is_rectangle = check_rectangle(map_line);
	if (is_rectangle == BAD_SIZE)
		return (BAD_SIZE);
	x = 0;
	if (map_line[0] != '1')
		return (WALLS_ERROR);
	while (map_line[x])
	{
		if (map_line[x] != '0' && map_line[x] != '1' && map_line[x] != 'E' && \
			map_line[x] != 'C' && map_line[x] != 'P' && map_line[x] != 'M' && \
			map_line[x] != '\n')
		{
			return (BAD_CHARACTER);
		}
		x++;
	}
	if (map_line[x - 2] != '1')
		return (WALLS_ERROR);
	return (NO_ERROR);
}

// Verifie les erreurs pour la premiere et derniere ligne puis envoie
// la map ligne par ligne a parsing_x.
int	parsing_y(char **map, int linenbr)
{
	int	y;
	int	error;

	y = 0;
	error = NO_ERROR;
	error = top_bottom_walls(map[0]);
	if (error != NO_ERROR)
		return (error);
	error = top_bottom_walls(map[linenbr]);
	if (error != NO_ERROR)
		return (error);
	while (map[y])
	{
		error = parsing_x(map[y++]);
		if (error != NO_ERROR)
			return (error);
	}
	return (error);
}

// Enregistre la map dans une tableau de tableau pour pouvoir
// lire ligne par ligne plus facilement et renvoi les erreur
// si besoin.
void	get_map(char **argv)
{
	char	**map_joined;
	int		fd;
	int		i;
	int		error;

	fd = open(argv[1], O_RDONLY);
	map_joined = (char **)malloc(sizeof(char *));
	if (!map_joined)
		return ;
	map_joined[0] = get_next_line(fd);
	i = 0;
	while (map_joined[i] != NULL)
		map_joined[++i] = get_next_line(fd);
	error = parsing_y(map_joined, i - 1);
	if (error != NO_ERROR)
		errors(error);
	error = pathfinding(map_joined, i - 1);
	if (error != NO_ERROR)
		errors(error);
}
