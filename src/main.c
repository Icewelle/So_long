/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:20:34 by cluby             #+#    #+#             */
/*   Updated: 2024/06/09 03:09:59 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Main ^^.
int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (0);
	checkarg(argv[1]);
	get_map(argv, &game);
	letsstart(&game);
	freemap(game.map);
	return (0);
}
