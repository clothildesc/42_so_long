/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:49:15 by cscache           #+#    #+#             */
/*   Updated: 2025/06/30 14:46:59 by cscache          ###   ########.fr       */
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

typedef enum e_directiom {
	DOWN,
	UP,
	RIGHT,
	LEFT,
	QUIT
}	t_direction;

typedef struct s_player_sprites {
	void	*walk_down[3];
	void	*walk_up[3];
	void	*walk_right[3];
	void	*walk_left[3];
}	t_player_sprites;

typedef struct s_img_game {
	void				*wall;
	void				*floor;
	t_player_sprites	player;
	void				*player_win;
	void				*collectible;
	void				*exit;
	void				*black;
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
	int			game_won;
	int			player_x;
	int			player_y;
	void		*mlx;
	void		*mlx_win;
	t_img_game	img;
	t_direction	direction;
	int			img_index;
}	t_game;

# define TILE_SIZE 64
# define MOVE_COUNT_ZONE 30

# define KEY_W 119
# define KEY_S 115
# define KEY_D 100
# define KEY_A 97
# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

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

//init window and images
void	init_window(t_game *g);
void	init_player_up_and_down(t_game *g);
void	init_player_right_and_left(t_game *g);
void	init_other_images(t_game *g);
void	init_images(t_game *g);

//mxl
void	paint_black_move_zone(t_game *g);
void	diplay_images(t_game *g, int x, int y, char tile);
void	render_map(t_game *g);
void	update_game(t_game *g, int new_x, int new_y);
void	show_game(t_game *g, char *file);
void	show_total_count(t_game *g);
int		move_player(t_game *g, int x, int y);
void	define_direction(t_game *g, int keycode);
int		key_handler(int keycode, void *param);

//free
void	free_grid_and_exit(t_game *g);
void	free_grid_cpy(char **grid_cpy);

//A SUPPRIMER
void	print_grid(char **grid);

#endif