/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 03:02:17 by cluby             #+#    #+#             */
/*   Updated: 2024/06/12 20:20:07 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static mlx_texture_t	*load_textures(t_game *game, char *path)
{
	mlx_texture_t *texture;

	texture = mlx_load_png(path);
	if (!texture)
        errors(MLX_ERROR, game->map);
	return (texture);
}

static void load_images(t_game *game, t_textures *texture)
{
	texture->player = load_textures(game, "./img/blue.png");
	texture->coins = load_textures(game, "./img/gold.png");
	texture->wall = load_textures(game, "./img/red.png");
	texture->ground = load_textures(game, "./img/white.png");
	game->img->player = mlx_texture_to_image(game->mlx, texture->player);
	if (!game->img->player)
        errors(MLX_ERROR, game->map);
	game->img->wall = mlx_texture_to_image(game->mlx, texture->wall);
	if (!game->img->wall)
        errors(MLX_ERROR, game->map);
	game->img->coins = mlx_texture_to_image(game->mlx, texture->coins);
	if (!game->img->coins)
        errors(MLX_ERROR, game->map);
	game->img->ground = mlx_texture_to_image(game->mlx, texture->ground);
	if (!game->img->ground)
        errors(MLX_ERROR, game->map);
}

static void	put_image(t_game *game)
{
	while (game->map[game->pos_y])
	{
		while (game->map[game->pos_y][game->pos_x])
		{
			if (game->map[game->pos_y][game->pos_x] == '1')
				if (mlx_image_to_window(game->mlx, game->img->wall,65 * \
				 game->pos_x, 65 * game->pos_y) < 0)
					errors(MLX_ERROR, game->map);
			if (game->map[game->pos_y][game->pos_x] == '0')
				if (mlx_image_to_window(game->mlx, game->img->ground, 65 * \
				 game->pos_x, 65 * game->pos_y) < 0)
					errors(MLX_ERROR, game->map);
			if (game->map[game->pos_y][game->pos_x] == 'C')
				if (mlx_image_to_window(game->mlx, game->img->coins, 65 * \
				 game->pos_x, 65 * game->pos_y) < 0)
					errors(MLX_ERROR, game->map);
			if (game->map[game->pos_y][game->pos_x] == 'P')
				if (mlx_image_to_window(game->mlx, game->img->player, 65 * \
				 game->pos_x, 65 * game->pos_y) < 0)
					errors(MLX_ERROR, game->map);
			game->pos_x++;
		}
		game->pos_y++;
		game->pos_x = 0;
	}
}

// Work in progress.
void	make_map(t_game *game, t_textures *texture)
{
	load_images(game, texture);
	put_image(game);
}
