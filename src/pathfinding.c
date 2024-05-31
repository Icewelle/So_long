/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:25:14 by cluby             #+#    #+#             */
/*   Updated: 2024/05/31 17:28:04 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Suite du parsing pour savoir si il manque des elements 
// (piece, joueur, sortie) ainsi que pour savoir si toutes 
// les pieces et la sortie sont possible a atteindre.
void	pathfinding(char **map, int linenbr)
{
	int	y;

	y = 0;
	while (y < linenbr)
		find_missing(map[y++], linenbr, map);
	
}
