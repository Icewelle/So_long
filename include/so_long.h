/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:39 by cluby             #+#    #+#             */
/*   Updated: 2024/07/05 11:26:12 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "../MLX42/include/MLX42/MLX42.h"
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
# define MLX_ERROR "MLX failed to initialize\n"
# define TILE_SIZE 64
# define GROUND 0
# define WALL 1
# define PLAYER 2
# define COINS 3
# define EXIT_IMG 4

typedef struct textures
{
	mlx_texture_t	*player;
	mlx_texture_t	*ground;
	mlx_texture_t	*wall;
	mlx_texture_t	*coins;
	mlx_texture_t	*exit;
}					t_textures;

typedef struct images
{
	mlx_image_t	*id;
}				t_images;

typedef struct game
{
	mlx_t		*mlx;
	char		**map;
	char		**temp_map;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			height;
	int			width;
	int			coinsnbr;
	int			playernbr;
	int			exitnbr;
	int			is_exit;
	int			pos_x;
	int			pos_y;
	int			moves;
	t_images	**img;
}				t_game;

void	get_map(char **argv, t_game *game);
void	errors(char *error, t_game *game);
void	pathfinding(t_game *game);
void	find_missing(char *map_line, t_game *game, int y);
void	freemap(char **map);
int		count_lines(char *map);
void	init_game(t_game *game);
void	makemap(t_game *game, int fd);
void	checkarg(char *filename);
void	make_map(t_game *game, t_textures *texture);
void	clean_kill(t_game *game);
void	init_img(t_game *game);
void	freeimg(t_images **img);
void	keyfunc(mlx_key_data_t keydata, void *game);
void	press_esc(t_game *game);
void	ft_put_image(t_game *game);
void	ft_put_image2(t_game *game, int x, int y);

#endif