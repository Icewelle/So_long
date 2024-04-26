/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:23 by cluby             #+#    #+#             */
/*   Updated: 2024/04/26 22:02:24 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	top_bottom_walls(char *map_line)
{
	int i;
	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != '1' && map_line[i] != '\n')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	parsing(char **map, int linenbr)
{
	int	x;
	int	y;
	int	error;

	y = 0;
	error = FALSE;
	while (map[y])
	{
		x = 0;
		printf("%s", map[y]);
		if (y == 0 || y == linenbr)
			error = top_bottom_walls(map[y]);
		y++;
	}
	return (error);
}

void	get_map(char **argv)
{
	char	**map_joined;
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	map_joined = (char **)malloc(sizeof(char *));
	if (!map_joined)
		return ;
	map_joined[0] = get_next_line(fd);
	i = 0;
	while ((map_joined[++i] = get_next_line(fd)) != NULL)
		map_joined[++i] = get_next_line(fd);
	if (parsing(map_joined, i) == TRUE)
		printf("error");
}
