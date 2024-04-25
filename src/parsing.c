/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:23 by cluby             #+#    #+#             */
/*   Updated: 2024/04/25 14:51:06 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	parsing(char **map)
{
	int i;

	i = 0;
	while (!map[i])
	{
		printf("%s", map[i++]);
	}
	return (0);
}
void	get_map(char **argv)
{
	char	**map;
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	map[0] = get_next_line(fd);
	printf("is ok\n");
	i = 1;
	while (map != NULL)
	{
		map[i++] = get_next_line(fd);
	}
	parsing(map);
}
