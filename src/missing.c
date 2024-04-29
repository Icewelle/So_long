/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 02:02:09 by cluby             #+#    #+#             */
/*   Updated: 2024/04/29 06:09:40 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	what_missing(int coin, int player, int exit)
{
	if (coin < 1)
		return (NO_PIECES_ERROR);
	if (player < 1)
		return (NO_PLAYER_ERROR);
	if (player > 1)
		return (TOO_MANY_PLAYER_ERROR);
	if (exit < 1)
		return (NO_EXIT_ERROR);
	if (exit > 1)
		return (TOO_MANY_EXIT_ERROR);
	return (NO_ERROR);
}

int	find_missing(char *map_line, int linenbr)
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
		return (what_missing(coin, player, exit));
	return (NO_ERROR);
}
