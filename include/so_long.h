/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:39 by cluby             #+#    #+#             */
/*   Updated: 2024/05/14 23:45:29 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# define NO_ERROR 0 //"Nothing to look at :D\n"
# define WALLS_ERROR 1 //"Walls aren't closed properly\n"
# define NO_PIECES_ERROR 2 //"There's no pieces on the map\n"
# define NO_EXIT_ERROR 3 //"There's no exit on the map\n"
# define NO_PLAYER_ERROR 4 //"There's no player on the map\n"
# define NO_PATH_EXIT 5 //"There's no path to the exit\n"
# define NO_PATH_PIECE 6 //"At least one piece cannot be taken\n"
# define BAD_SIZE 7 //"The map isn't rectangular"
# define BAD_CHARACTER 8 //"One or more character isn't allowed\n"
# define TOO_MANY_EXIT_ERROR 9 //"There's too many exit on the map\n"
# define TOO_MANY_PLAYER_ERROR 10 //"There's too many player on the map\n"

typedef struct s_navpoint
{
	int	x;
	int	y;
	int	right_x;
	int	right_y;
	int	right_bottom_x;
	int	right_bottom_y;
	int	bottom_x;
	int	bottom_y;
	int	platform_index;
	int	navpoint_type;
}		t_navpoint;

char	**get_map(char **argv);
void	errors(int error);
int		pathfinding(char **map, int linenbr);
int		find_missing(char *map_line, int linenbr);
void	freemap(char **map);

#endif