/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:39 by cluby             #+#    #+#             */
/*   Updated: 2024/06/09 03:16:43 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# define NO_ERROR "Nothing to look at :D\n"
# define WALLS_ERROR "Walls aren't closed properly\n"
# define NO_PIECES_ERROR "There's no pieces on the map\n"
# define NO_EXIT_ERROR "There's no exit on the map\n"
# define NO_PLAYER_ERROR "There's no player on the map\n"
# define NO_PATH_EXIT "There's no path to the exit\n"
# define NO_PATH_PIECE "At least one piece cannot be taken\n"
# define BAD_SIZE "The map isn't rectangular\n"
# define BAD_CHARACTER "One or more character isn't allowed\n"
# define TOO_MANY_EXIT_ERROR "There's too many exit on the map\n"
# define TOO_MANY_PLAYER_ERROR "There's too many player on the map\n"
# define OPEN_ERROR "Couldn't open the file\n"
# define MALLOC_ERROR "Couldn't allocate memory\n"
# define ERROR_PATH "Couldn't find a path to the exit or a collectible\n"
# define FILLED 'F'
# define MAP_ERROR "Map is empty\n"
# define FILE_NAME "File isn't a .ber\n"

typedef struct game
{
	mlx_t	*mlx;
	char	**map;
	char	**temp_map;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		height;
	int		width;
	int		coinsnbr;
	int		playernbr;
	int		exitnbr;
	int		is_exit;
}			t_game;

void	get_map(char **argv, t_game *game);
void	errors(char *error, char **map);
void	pathfinding(t_game game);
void	find_missing(char *map_line, t_game *game, int y);
void	freemap(char **map);
int		count_lines(char *map);
void	init_game(t_game *game);
void	makemap(t_game *game, int fd);
void	checkarg(char *filename);
void	letsstart(t_game *game);

#endif