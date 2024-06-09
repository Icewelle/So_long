/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:25:14 by cluby             #+#    #+#             */
/*   Updated: 2024/06/09 02:42:25 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	flood_fill(t_game *game, int x, int y, int collect)
{
	if (x < 0 || y < 0 || x > game->width - 1 || y > game->height - 1)
		return (0);
	if (game->temp_map[y][x] == '1' || game->temp_map[y][x] == FILLED)
		return (0);
	if (game->temp_map[y][x] == 'C')
		(collect)--;
	if (game->temp_map[y][x] == 'E')
		game->is_exit = 1;
	if (game->is_exit == 1 && collect == 0)
		return (1);
	game->temp_map[y][x] = FILLED;
	if (flood_fill(game, x + 1, y, collect) || \
		flood_fill(game, x - 1, y, collect) || \
		flood_fill(game, x, y + 1, collect) || \
		flood_fill(game, x, y - 1, collect))
		return (1);
	return (0);
}

static void	cpymap(t_game *game)
{
	int	y;

	game->temp_map = (char **)ft_calloc(game->height + 1, sizeof(char *));
	if (!game->temp_map)
		errors(MALLOC_ERROR, game->map);
	y = 0;
	while (y < game->height)
	{
		game->temp_map[y] = ft_strdup(game->map[y]);
		if (!game->temp_map[y])
		{
			freemap(game->temp_map);
			errors(MALLOC_ERROR, game->map);
		}
		y++;
	}
}

// Suite du parsing pour savoir si il manque des elements 
// (piece, joueur, sortie) ainsi que pour savoir si toutes 
// les pieces et la sortie sont possible a atteindre.
void	pathfinding(t_game game)
{
	int	y;

	y = 0;
	while (y < game.height)
	{
		find_missing(game.map[y], &game, y);
		y++;
	}
	cpymap(&game);
	if (!(flood_fill(&game, game.player_x, game.player_y, game.coinsnbr)))
	{
		freemap(game.temp_map);
		errors(ERROR_PATH, game.map);
	}
	freemap(game.temp_map);
}
