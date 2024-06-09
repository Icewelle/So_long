/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:37:14 by cluby             #+#    #+#             */
/*   Updated: 2024/06/09 03:33:53 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Display errors and free the previously malloced map.
void	errors(char *error, char	**map)
{
	ft_printf("%s", error);
	freemap(map);
	exit(EXIT_FAILURE);
}
