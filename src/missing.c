/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 02:02:09 by cluby             #+#    #+#             */
/*   Updated: 2024/06/28 13:01:00 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Do the final check for the missing element to be sure there's not
// too little or too many elements.
static void	what_missing(t_game game)
{
	if (game.playernbr < 1)
		errors(NO_PLAYER_ERROR, game.map, game.img);
	if (game.playernbr > 1)
		errors(TOO_MANY_PLAYER_ERROR, game.map, game.img);
	if (game.coinsnbr < 1)
		errors(NO_PIECES_ERROR, game.map, game.img);
	if (game.exitnbr < 1)
		errors(NO_EXIT_ERROR, game.map, game.img);
	if (game.exitnbr > 1)
		errors(TOO_MANY_EXIT_ERROR, game.map, game.img);
}

// Check if the map is missing elements like a collectible an exit or
// the player starting point.
void	find_missing(char *map_line, t_game *game, int y)
{
	static int	i;
	int			x;

	x = 0;
	while (map_line[x])
	{
		if (map_line[x] == 'P')
		{
			game->playernbr++;
			game->player_x = x;
			game->player_y = y;
		}
		if (map_line[x] == 'C')
			game->coinsnbr++;
		if (map_line[x] == 'E')
		{
			game->exitnbr++;
			game->exit_x = x;
			game->exit_y = y;
		}
		x++;
	}
	i++;
	if (i == game->height - 1)
		what_missing(*game);
}
