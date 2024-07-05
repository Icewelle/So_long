/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:59:32 by cluby             #+#    #+#             */
/*   Updated: 2024/07/05 11:33:19 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	press_w(t_game *game)
{
	if (game->map[game->pos_y - 1][game->pos_x] == '1')
		return ;
	else if (game->map[game->pos_y - 1][game->pos_x] == 'C')
	{
		game->map[game->pos_y - 1][game->pos_x] = '0';
		game->coinsnbr--;
	}
	game->moves++;
	ft_printf("Move count : %d\n", game->moves);
	if (game->map[game->pos_y - 1][game->pos_x] == 'E' && game->coinsnbr < 1)
		clean_kill(game);
	game->pos_y--;
	ft_put_image2(game, 0, 1);
	if (game->map[game->pos_y + 1][game->pos_x] == 'E' && game->coinsnbr > 0)
	{
		mlx_image_to_window(game->mlx, game->img[EXIT_IMG]->id, \
		(game->exit_x) * (TILE_SIZE + 1), (game->exit_y) * (TILE_SIZE + 1));
	}
}

static void	press_a(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x - 1] == '1')
		return ;
	else if (game->map[game->pos_y][game->pos_x - 1] == 'C')
	{
		game->map[game->pos_y][game->pos_x - 1] = '0';
		game->coinsnbr--;
	}
	game->moves++;
	ft_printf("Move count : %d\n", game->moves);
	if (game->map[game->pos_y][game->pos_x - 1] == 'E' && game->coinsnbr < 1)
		clean_kill(game);
	game->pos_x--;
	ft_put_image2(game, 1, 0);
	if (game->map[game->pos_y][game->pos_x + 1] == 'E' && game->coinsnbr > 0)
	{
		mlx_image_to_window(game->mlx, game->img[EXIT_IMG]->id, \
		(game->exit_x) * (TILE_SIZE + 1), (game->exit_y) * (TILE_SIZE + 1));
	}
}

static void	press_s(t_game *game)
{
	if (game->map[game->pos_y + 1][game->pos_x] == '1')
		return ;
	else if (game->map[game->pos_y + 1][game->pos_x] == 'C')
	{
		game->map[game->pos_y + 1][game->pos_x] = '0';
		game->coinsnbr--;
	}
	game->moves++;
	ft_printf("Move count : %d\n", game->moves);
	if (game->map[game->pos_y + 1][game->pos_x] == 'E' && game->coinsnbr < 1)
		clean_kill(game);
	game->pos_y++;
	ft_put_image2(game, 0, -1);
	if (game->map[game->pos_y - 1][game->pos_x] == 'E' && game->coinsnbr > 0)
	{
		mlx_image_to_window(game->mlx, game->img[EXIT_IMG]->id, \
		(game->exit_x) * (TILE_SIZE + 1), (game->exit_y) * (TILE_SIZE + 1));
	}
}

static void	press_d(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x + 1] == '1')
		return ;
	else if (game->map[game->pos_y][game->pos_x + 1] == 'C')
	{
		game->map[game->pos_y][game->pos_x + 1] = '0';
		game->coinsnbr--;
	}
	game->moves++;
	ft_printf("Move count : %d\n", game->moves);
	if (game->map[game->pos_y][game->pos_x + 1] == 'E' && game->coinsnbr < 1)
		clean_kill(game);
	game->pos_x++;
	ft_put_image2(game, -1, 0);
	if (game->map[game->pos_y][game->pos_x - 1] == 'E' && game->coinsnbr > 0)
	{
		mlx_image_to_window(game->mlx, game->img[EXIT_IMG]->id, \
		(game->exit_x) * (TILE_SIZE + 1), (game->exit_y) * (TILE_SIZE + 1));
	}
}

void	keyfunc(mlx_key_data_t keydata, void *tgame)
{
	t_game	*game;

	game = (t_game *)tgame;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		press_w(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		press_a(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		press_s(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		press_d(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		press_esc(game);
	if (game->coinsnbr < 1)
		mlx_image_to_window(game->mlx, game->img[COINS]->id, \
		(game->exit_x) * (TILE_SIZE + 1), (game->exit_y) * (TILE_SIZE + 1));
}
