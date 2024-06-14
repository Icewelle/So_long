/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:59:32 by cluby             #+#    #+#             */
/*   Updated: 2024/06/15 00:33:42 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	keyfunc(mlx_key_data_t keydata, void *tgame)
{
	t_game	*game;
	game = (t_game *)tgame;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (game->map[game->pos_y - 1][game->pos_x] == '1')
			return ;
		game->pos_y--;
		game->img[PLAYER]->id->instances[0].y -= TILE_SIZE + 1;
		mlx_image_to_window(game->mlx, game->img[GROUND]->id, game->pos_x * (TILE_SIZE + 1), (game->pos_y + 1) * (TILE_SIZE + 1));
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (game->map[game->pos_y][game->pos_x - 1] == '1' || game->map[game->pos_y][game->pos_x - 1] == 'E')
			return ;
		game->pos_x--;
		game->img[PLAYER]->id->instances[0].x -= TILE_SIZE + 1;
		mlx_image_to_window(game->mlx, game->img[GROUND]->id, (game->pos_x + 1) * (TILE_SIZE + 1), (game->pos_y) * (TILE_SIZE + 1));
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		if (game->map[game->pos_y + 1][game->pos_x] == '1' || game->map[game->pos_y + 1][game->pos_x] == 'E')
			return ;
		game->pos_y++;
		game->img[PLAYER]->id->instances[0].y += TILE_SIZE + 1;
		mlx_image_to_window(game->mlx, game->img[GROUND]->id, game->pos_x * (TILE_SIZE + 1), (game->pos_y - 1) * (TILE_SIZE + 1));
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		if (game->map[game->pos_y][game->pos_x + 1] == '1' || game->map[game->pos_y][game->pos_x + 1] == 'E')
			return ;
		game->pos_x++;
		game->img[PLAYER]->id->instances[0].x += TILE_SIZE + 1;
		mlx_image_to_window(game->mlx, game->img[GROUND]->id, (game->pos_x - 1) * (TILE_SIZE + 1), (game->pos_y) * (TILE_SIZE + 1));
	}
}
