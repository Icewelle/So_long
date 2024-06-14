/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 03:02:17 by cluby             #+#    #+#             */
/*   Updated: 2024/06/15 00:20:03 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static mlx_texture_t	*load_textures(t_game *game, char *path)
{
	mlx_texture_t *texture;

	texture = mlx_load_png(path);
	if (!texture)
        errors(MLX_ERROR, game->map, game->img);
	return (texture);
}

static void load_images(t_game *game, t_textures *texture)
{
	texture->player = load_textures(game, "./img/blue.png");
	texture->coins = load_textures(game, "./img/gold.png");
	texture->wall = load_textures(game, "./img/red.png");
	texture->ground = load_textures(game, "./img/white.png");
	game->img[GROUND]->id = mlx_texture_to_image(game->mlx, texture->ground);
	if (!game->img[0]->id)
        errors(MLX_ERROR, game->map, game->img);
	game->img[WALL]->id = mlx_texture_to_image(game->mlx, texture->wall);
	if (!game->img[WALL]->id)
        errors(MLX_ERROR, game->map, game->img);
	game->img[COINS]->id = mlx_texture_to_image(game->mlx, texture->coins);
	if (!game->img[COINS]->id)
        errors(MLX_ERROR, game->map, game->img);
	game->img[PLAYER]->id = mlx_texture_to_image(game->mlx, texture->player);
	if (!game->img[PLAYER]->id)
        errors(MLX_ERROR, game->map, game->img);
}

static void	put_image(t_game *game)
{
	while (game->map[game->pos_y])
	{
		while (game->map[game->pos_y][game->pos_x])
		{
			if (game->map[game->pos_y][game->pos_x] == '1')
				if (mlx_image_to_window(game->mlx, game->img[WALL]->id, 65 * \
				 game->pos_x, 65 * game->pos_y) < 0)
					errors(MLX_ERROR, game->map, game->img);
			if (game->map[game->pos_y][game->pos_x] == '0')
				if (mlx_image_to_window(game->mlx, game->img[GROUND]->id, 65 * \
				 game->pos_x, 65 * game->pos_y) < 0)
					errors(MLX_ERROR, game->map, game->img);
			if (game->map[game->pos_y][game->pos_x] == 'C')
				if (mlx_image_to_window(game->mlx, game->img[COINS]->id, 65 * \
				 game->pos_x, 65 * game->pos_y) < 0)
					errors(MLX_ERROR, game->map, game->img);
			if (game->map[game->pos_y][game->pos_x] == 'P')
				if (mlx_image_to_window(game->mlx, game->img[PLAYER]->id, 65 * \
				 game->pos_x, 65 * game->pos_y) < 0)
					errors(MLX_ERROR, game->map, game->img);
			game->pos_x++;
		}
		game->pos_y++;
		game->pos_x = 0;
	}
}

// Work in progress.
void	make_map(t_game *game, t_textures *texture)
{
	int found = 0;
	int y = 0;
	load_images(game, texture);
	put_image(game);
	game->pos_x = 0;
	game->pos_y = 0;
	while (y < game->height && !found) {
		int x = 0;
		while (x < game->width && !found) {
			if (game->map[y][x] == 'P') {
				game->pos_y = y;
				game->pos_x = x;
				found = 1;
			}
			x++;
		}
		y++;
	}
}
