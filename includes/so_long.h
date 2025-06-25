/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:49:15 by cscache           #+#    #+#             */
/*   Updated: 2025/06/25 17:27:14 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct s_img_game {
	void	*wall;
	void	*floor;
	void	*player;
	void	*player_win;
	void	*collectible;
	void	*exit;
}	t_img_game;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	char		**grid;
	int			width;
	int			height;
	int			collectibles;
	int			player_count;
	int			exit_count;
	int			move_count;
	int			player_x;
	int			player_y;
	void		*mlx;
	void		*mlx_win;
	t_img_game	img;
}	t_game;

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# ifndef KEY_UP
#  define KEY_UP 119
# endif

# ifndef KEY_DOWN
#  define KEY_DOWN 115
# endif

# ifndef KEY_RIGHT
#  define KEY_RIGHT 100
# endif

# ifndef KEY_LEFT
#  define KEY_LEFT 97
# endif

//init grid
void	init_struct_game(t_game *g);
int		open_file(const char *file);
void	init_height(const char *file, t_game *g);
void	remove_newline(char *line);
void	init_grid(const char *file, t_game *g);

//check grid
int		init_width_and_check_rectangularity(t_game *g);
int		check_walls(t_game *g);
int		count_elements(const char *s, char c);
int		is_in_dataset(char c);
int		check_rules_for_elements(t_game *g);
void	init_counters(t_game *g, char c, int x, int y);
int		check_elements(t_game *g);
void	flood_fill(char **grid_cpy, t_point size, int row, int col);
char	**create_grid_cpy(char **grid, int size);
int		check_accessility(t_game *g);
int		validate_map(t_game *g);
int		load_map(t_game *g, char *file);

//free
void	free_grid_and_exit(t_game *g);
void	free_grid_cpy(char **grid_cpy);

//mxl
void	init_window(t_game *g);
void	init_images(t_game *g);
void	render_map(t_game *g);
void	show_game(t_game *g, char *file);
int		move_player(t_game *g, int x, int y);
int		key_handler(int keycode, void *param);

//A SUPPRIMER
void	print_grid(char **grid);

#endif