/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:37:14 by cluby             #+#    #+#             */
/*   Updated: 2024/07/02 15:47:28 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Display errors and free the previously malloced map.
void	errors(char *error, t_game *game)
{
	ft_printf("%s", error);
	if (game)
	{
		if (game->map)
			freemap(game->map);
		if (game->img)
			freeimg(game->img);
		if (game->mlx)
			mlx_terminate(game->mlx);
	}
	exit(EXIT_FAILURE);
}
