/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:25:14 by cluby             #+#    #+#             */
/*   Updated: 2024/04/29 06:01:27 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Suite du parsing pour savoir si il manque des elements 
// (piece, joueur, sortie) ainsi que pour savoir si toutes 
// les pieces et la sortie sont possible a atteindre.
int	pathfinding(char **map, int linenbr)
{
	int	y;
	int	error;

	y = 0;
	while (y < linenbr)
	{
		error = find_missing(map[y], linenbr);
		if (error != NO_ERROR)
			return (error);
		y++;
	}
	return (error);
}
