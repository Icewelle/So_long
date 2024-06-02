/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 02:02:09 by cluby             #+#    #+#             */
/*   Updated: 2024/06/01 15:13:02 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Verifie si il manque ou si il y a trop de characters obligatoires.
static void	what_missing(t_game game)
{
	if (game.playernbr < 1)
		errors(NO_PLAYER_ERROR, game.map);
	if (game.playernbr > 1)
		errors(TOO_MANY_PLAYER_ERROR, game.map);
	if (game.coinsnbr < 1)
		errors(NO_PIECES_ERROR, game.map);
	if (game.exitnbr < 1)
		errors(NO_EXIT_ERROR, game.map);
	if (game.exitnbr > 1)
		errors(TOO_MANY_EXIT_ERROR, game.map);
}

// Compte le nombre de characters obligatoire avant de verifier si la quantite
// obtenu est correct.
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
