/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 03:02:17 by cluby             #+#    #+#             */
/*   Updated: 2024/06/28 13:06:04 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_texture_t	*load_textures(t_game *game, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		errors(MLX_ERROR, game->map, game->img);
	return (texture);
}

static void	load_images(t_game *game, t_textures *texture)
{
	texture->player = load_textures(game, "./img/blue.png");
	texture->coins = load_textures(game, "./img/gold.png");
	texture->exit = load_textures(game, "./img/black.png");
	texture->wall = load_textures(game, "./img/red.png");
	texture->ground = load_textures(game, "./img/white.png");
	game->img[EXIT_IMG]->id = mlx_texture_to_image(game->mlx, texture->exit);
	if (!game->img[EXIT_IMG]->id)
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
	game->img[GROUND]->id = mlx_texture_to_image(game->mlx, texture->ground);
	if (!game->img[0]->id)
		errors(MLX_ERROR, game->map, game->img);
	mlx_delete_texture(texture->player);
	mlx_delete_texture(texture->coins);
	mlx_delete_texture(texture->wall);
	mlx_delete_texture(texture->ground);
	mlx_delete_texture(texture->exit);
}

static void	put_image(t_game *game)
{
	while (game->map[game->pos_y])
	{
		while (game->map[game->pos_y][game->pos_x])
		{
			ft_put_image(game);
			game->pos_x++;
		}
		game->pos_y++;
		game->pos_x = 0;
	}
}

// Work in progress.
void	make_map(t_game *game, t_textures *texture)
{
	int	found;
	int	y;
	int	x;

	load_images(game, texture);
	put_image(game);
	game->pos_x = 0;
	game->pos_y = 0;
	y = 0;
	found = 0;
	while (y < game->height && !found)
	{
		x = 0;
		while (x < game->width && !found)
		{
			if (game->map[y][x] == 'P')
			{
				game->pos_y = y;
				game->pos_x = x;
				found = 1;
			}
			x++;
		}
		y++;
	}
}
