/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:59:32 by cluby             #+#    #+#             */
/*   Updated: 2024/06/12 20:05:49 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	keyfunc(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(game->mlx, image)
	}
}