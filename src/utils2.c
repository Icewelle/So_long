/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:52:50 by cluby             #+#    #+#             */
/*   Updated: 2024/06/28 13:05:28 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_game *game)
{
	game->img = (t_images **)malloc(sizeof(t_images *) * 6);
	if (!game->img)
		errors(MALLOC_ERROR, NULL, NULL);
	game->img[GROUND] = (t_images *)malloc(sizeof(t_images));
	game->img[WALL] = (t_images *)malloc(sizeof(t_images));
	game->img[COINS] = (t_images *)malloc(sizeof(t_images));
	game->img[PLAYER] = (t_images *)malloc(sizeof(t_images));
	game->img[EXIT_IMG] = (t_images *)malloc(sizeof(t_images));
	if (!game->img[GROUND] || !game->img[WALL] || !game->img[COINS] || \
		!game->img[PLAYER])
		errors(MALLOC_ERROR, NULL, game->img);
}

void	freeimg(t_images **img)
{
	int	i;

	i = 0;
	if (!img)
		return ;
	while (i < 5)
	{
		if (img[i])
		{
			free(img[i]);
			img[i] = NULL;
		}
		i++;
	}
	free(img);
}

void	press_esc(t_game *game)
{
	clean_kill(game);
}

void	ft_put_image(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x] == 'E')
		if (mlx_image_to_window(game->mlx, game->img[EXIT_IMG]->id, 65 * \
		game->pos_x, 65 * game->pos_y) < 0)
			errors(MLX_ERROR, game->map, game->img);
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
}
