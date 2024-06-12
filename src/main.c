/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:20:34 by cluby             #+#    #+#             */
/*   Updated: 2024/06/12 20:20:21 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Main ^^.
int	main(int argc, char *argv[])
{
	t_game		game;
	t_textures	texture;

	if (argc != 2)
		return (0);
	checkarg(argv[1]);
	get_map(argv, &game);
	game.mlx = mlx_init(game.width * (TILE_SIZE + 1), \
	game.height * (TILE_SIZE + 1), "So_long", true);
	if (!(game.mlx))
		errors(MLX_ERROR, game.map);
	make_map(&game, &texture);
	//mlx_key_hook(game.mlx, &keyfunc, &game);
	mlx_loop(game.mlx);
	clean_kill(&game, &texture);
	return (0);
}
