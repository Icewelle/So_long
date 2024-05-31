/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 02:02:09 by cluby             #+#    #+#             */
/*   Updated: 2024/05/31 16:06:27 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Verifie si il manque ou si il y a trop de characters obligatoires.
void	what_missing(int coin, int player, int exit, char **map)
{
	if (coin < 1)
		errors(NO_PIECES_ERROR, map);
	if (player < 1)
		errors(NO_PLAYER_ERROR, map);
	if (player > 1)
		errors(TOO_MANY_PLAYER_ERROR, map);
	if (exit < 1)
		errors(NO_EXIT_ERROR, map);
	if (exit > 1)
		errors(TOO_MANY_EXIT_ERROR, map);
}

// Compte le nombre de characters obligatoire avant de verifier si la quantite
// obtenu est correct.
void	find_missing(char *map_line, int linenbr, char **map)
{
	static int	coin;
	static int	player;
	static int	exit;
	static int	i;
	int			x;

	x = 0;
	while (map_line[x])
	{
		if (map_line[x] == 'P')
			player++;
		if (map_line[x] == 'C')
			coin++;
		if (map_line[x] == 'E')
			exit++;
		x++;
	}
	i++;
	if (i == linenbr)
		what_missing(coin, player, exit, map);
}
