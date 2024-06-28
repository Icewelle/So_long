/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:37:14 by cluby             #+#    #+#             */
/*   Updated: 2024/06/28 13:05:16 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Display errors and free the previously malloced map.
void	errors(char *error, char	**map, t_images **img)
{
	ft_printf("%s", error);
	freemap(map);
	freeimg(img);
	exit(EXIT_FAILURE);
}
