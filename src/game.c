/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 03:02:17 by cluby             #+#    #+#             */
/*   Updated: 2024/06/09 03:09:20 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	letsstart(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		ft_printf("%s", game->map[i]);
		i++;
	}
}
