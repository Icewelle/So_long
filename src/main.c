/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:20:34 by cluby             #+#    #+#             */
/*   Updated: 2024/06/01 14:47:43 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Main ^^.
int	main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
		return (0);
	get_map(argv, &game);
	freemap(game.map);
	return (0);
}
