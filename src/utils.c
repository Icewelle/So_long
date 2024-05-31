/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:13:13 by cluby             #+#    #+#             */
/*   Updated: 2024/05/31 18:13:27 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	freemap(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

int	count_lines(char *map)
{
	int		lines;
	int		fd;
	char	*buffer;
	int		bytesread;
	int		i;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (close(fd), 0);
	bytesread = 1;
	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread == -1)
		return (free(buffer), close(fd), 0);
	lines = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			lines++;
		i++;
	}
	return (free(buffer), close(fd), lines);
}

void	init_game(t_game *game)
{
	game->map = NULL;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->height = 0;
	game->width = 0;
}