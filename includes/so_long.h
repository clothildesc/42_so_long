/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:49:15 by cscache           #+#    #+#             */
/*   Updated: 2025/07/02 16:08:06 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <time.h>
# include "../libft/libft.h"

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

# define MAX_ENEMIES 200

typedef enum e_direction {
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
	void				*chicken[5];
}	t_img_game;

typedef struct s_point
{
	int				x;
	int				y;
}	t_point;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	direction;
}	t_enemy;

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
	int			game_lose;
	int			player_x;
	int			player_y;
	void		*mlx;
	void		*mlx_win;
	t_img_game	img;
	t_direction	direction;
	t_direction	previous_direction;
	int			img_index;
	int			enemies_count;
	t_enemy		enemies[MAX_ENEMIES];
	int			tick;
}	t_game;

//init grid
void	init_struct_game(t_game *g);
int		check_extension(const char *file);
int		open_file(const char *file);
void	init_height(const char *file, t_game *g);
void	remove_newline(char *line);
void	init_grid(const char *file, t_game *g);

//check grid
int		init_width_and_check_rectangularity(t_game *g);
int		check_walls(t_game *g);
int		is_in_dataset(char c);
int		check_rules_for_elements(t_game *g);
void	init_counters(t_game *g, char c, int x, int y);
int		check_elements(t_game *g);
void	flood_fill(char **grid_cpy, t_point size, int row, int col);
char	**create_grid_cpy(char **grid, int size);
int		check_accessility(t_game *g);
int		validate_map(t_game *g);
int		load_map(t_game *g, char *file);

//init window
void	init_window(t_game *g);

//init images
void	init_player_up_and_down(t_game *g);
void	init_player_right_and_left(t_game *g);
void	init_other_images(t_game *g);
void	init_chicken_sprites(t_game *g);
void	init_images(t_game *g);

//display move_count
void	draw_black_move_zone(t_game *g);
void	display_move_count(t_game *g);

//display game
void	render_tiles_images(t_game *g, int x, int y, char tile);
void	render_player_sprites(t_game *g);
void	render_enemies(t_game *g);
void	render_map(t_game *g);

//manage game
void	update_game(t_game *g, int new_x, int new_y);
int		handle_player_movement(t_game *g, int x, int y);
void	set_player_direction(t_game *g, int keycode);
int		handle_key_input(int keycode, void *param);
int		close_window(void *param);

// run game
void	initialize_and_start_game(t_game *g);
void	display_error_message(char *message);

//free
void	free_grid_cpy(char **grid_cpy);
void	free_grid(t_game *g);
void	clean_exit(t_game *g, int exit_code);
void	destroy_player_sprites(t_game *g);
void	destroy_other_images(t_game *g);

//bonus
int		calculate_size_array_coordinates(t_game *g);
void	fill_array_positions(t_game *g, t_point *positions);
t_point	*create_array_positions(t_game *g, int size);
void	shuffle_positions(t_point *positions, int size);
void	move_enemy(t_game *g, t_enemy *c);
void	move_all_enemies(t_game *g, int step);
void	place_enemies(t_game *g, t_point *positions, int size);
void	create_enemies(t_game *g);
int		handle_tick(t_game *g);
void	check_if_game_over(t_game *g);

#endif