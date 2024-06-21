/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:52:50 by cluby             #+#    #+#             */
/*   Updated: 2024/06/18 19:07:42 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_img(t_game *game)
{
	game->img = (t_images **)malloc(sizeof(t_images *) * 5);
	if (!game->img)
		errors(MALLOC_ERROR, NULL, NULL);
	game->img[GROUND] = (t_images *)malloc(sizeof(t_images));
	game->img[WALL] = (t_images *)malloc(sizeof(t_images));
	game->img[COINS] = (t_images *)malloc(sizeof(t_images));
	game->img[PLAYER] = (t_images *)malloc(sizeof(t_images));
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
	while (i < 4)
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

void	press_esc(t_game *game, mlx_key_data_t keydata)
{
	(void)keydata;
	clean_kill(game, NULL);
}
