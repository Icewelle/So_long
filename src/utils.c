/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:13:13 by cluby             #+#    #+#             */
/*   Updated: 2024/06/12 20:28:49 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Free the malloced maps
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

// Count the lines in the file map to use them later, to malloc properly
// and also to have the height of the map.
int	count_lines(char *map)
{
	int		linenbr;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	linenbr = 0;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		linenbr++;
	}
	free (line);
	close(fd);
	return (linenbr);
}

// Initialize most of the game datas to be able to use everything later.
void	init_game(t_game game)
{
	game.map = NULL;
	game.temp_map = NULL;
	game.player_x = 0;
	game.player_y = 0;
	game.exit_x = 0;
	game.exit_y = 0;
	game.height = 0;
	game.width = 0;
	game.coinsnbr = 0;
	game.playernbr = 0;
	game.exitnbr = 0;
	game.is_exit = 0;
	game.pos_x = 0;
	game.pos_y = 0;
	game.img->coins = 0;
	game.img->wall = 0;
	game.img->player = 0;
	game.img->ground = 0;
	
}

// Register the map from the file into a malloced array of array. 
// One array per line to which make it one string per line, easier
// to read and use later for parsing and to display the tiles.
void	makemap(t_game *game, int fd)
{
	int	i;

	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		errors(MALLOC_ERROR, NULL);
	game->map[0] = get_next_line(fd);
	if (!game->map[0])
		exit(EXIT_FAILURE);
	i = 0;
	while (game->map[i] != NULL)
	{
		game->map[++i] = get_next_line(fd);
		if (!game->map[i] && i != game->height)
			errors(MALLOC_ERROR, game->map);
	}
}

void	clean_kill(t_game *game, t_textures *texture)
{
	freemap(game->map);
	mlx_delete_image(game->mlx, game->img->wall);
	mlx_delete_texture(texture->wall);
	mlx_delete_image(game->mlx, game->img->coins);
	mlx_delete_texture(texture->coins);
	mlx_delete_image(game->mlx, game->img->ground);
	mlx_delete_texture(texture->ground);
	mlx_delete_image(game->mlx, game->img->player);
	mlx_delete_texture(texture->player);
	mlx_terminate(game->mlx);
}
