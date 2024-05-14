/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:37:14 by cluby             #+#    #+#             */
/*   Updated: 2024/05/08 16:37:00 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Affiche les differents messages d'erreurs.
void	errors(int error)
{
	if (error == WALLS_ERROR)
		ft_putstr_fd("Error : Walls aren't closed properly\n", 2);
	if (error == NO_PIECES_ERROR)
		ft_putstr_fd("Error : There's no pieces on the map\n", 2);
	if (error == NO_EXIT_ERROR)
		ft_putstr_fd("Error : There's no exit on the map\n", 2);
	if (error == TOO_MANY_EXIT_ERROR)
		ft_putstr_fd("Error : There's too many exit on the map\n", 2);
	if (error == NO_PLAYER_ERROR)
		ft_putstr_fd("Error : There's no player on the map\n", 2);
	if (error == TOO_MANY_PLAYER_ERROR)
		ft_putstr_fd("Error : There's too many player on the map\n", 2);
	if (error == NO_PATH_EXIT)
		ft_putstr_fd("Error : There's no path to the exit\n", 2);
	if (error == NO_PATH_PIECE)
		ft_putstr_fd("Error : At least one piece cannot be taken\n", 2);
	if (error == BAD_SIZE)
		ft_putstr_fd("Error : The map isn't rectangular", 2);
	if (error == BAD_CHARACTER)
		ft_putstr_fd("Error : One or more character isn't allowed\n", 2);
}
