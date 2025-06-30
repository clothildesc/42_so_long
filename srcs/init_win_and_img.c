/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_and_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:55:36 by cscache           #+#    #+#             */
/*   Updated: 2025/06/30 17:18:30 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_game *g)
{
	int	window_height;
	int	window_width;

	window_height = g->height * TILE_SIZE + MOVE_COUNT_ZONE;
	window_width = g->width * TILE_SIZE;
	g->mlx = mlx_init();
	if (!g->mlx)
	{
		error_message("Failed to initialize MLX");
		free_grid_and_exit(g);
	}
	g->mlx_win = mlx_new_window(g->mlx, window_width, window_height, "so long");
	if (!g->mlx_win)
	{
		error_message("Failed to  open window");
		free_grid_and_exit(g);
	}
}

void	init_player_up_and_down(t_game *g)
{
	int		img_width;
	int		img_height;

	g->img.player.walk_down[0] = mlx_xpm_file_to_image(g->mlx, \
		"assets/player_down-1.xpm", &img_width, &img_height);
	g->img.player.walk_down[1] = mlx_xpm_file_to_image(g->mlx, \
		"assets/player_down-2.xpm", &img_width, &img_height);
	g->img.player.walk_down[2] = mlx_xpm_file_to_image(g->mlx, \
		"assets/player_down-3.xpm", &img_width, &img_height);
	g->img.player.walk_up[0] = mlx_xpm_file_to_image(g->mlx, \
		"assets/player_up-1.xpm", &img_width, &img_height);
	g->img.player.walk_up[1] = mlx_xpm_file_to_image(g->mlx, \
		"assets/player_up-2.xpm", &img_width, &img_height);
	g->img.player.walk_up[2] = mlx_xpm_file_to_image(g->mlx, \
		"assets/player_up-3.xpm", &img_width, &img_height);
	if (!g->img.player.walk_up[0] || !g->img.player.walk_up[1] \
		|| !g->img.player.walk_up[2] || !g->img.player.walk_down[0] \
		|| !g->img.player.walk_down[1] || !g->img.player.walk_down[2])
	{
		error_message("Failed to load image");
		free_grid_and_exit(g);
	}
}

void	init_player_right_and_left(t_game *g)
{
	int		img_width;
	int		img_height;

	g->img.player.walk_right[0] = mlx_xpm_file_to_image(g->mlx, \
		"assets/player_right-1.xpm", &img_width, &img_height);
	g->img.player.walk_right[1] = mlx_xpm_file_to_image(g->mlx, \
		"assets/player_right-2.xpm", &img_width, &img_height);
	g->img.player.walk_right[2] = mlx_xpm_file_to_image(g->mlx, \
		"assets/player_right-3.xpm", &img_width, &img_height);
	g->img.player.walk_left[0] = mlx_xpm_file_to_image(g->mlx, \
		"assets/player_left-1.xpm", &img_width, &img_height);
	g->img.player.walk_left[1] = mlx_xpm_file_to_image(g->mlx, \
		"assets/player_left-2.xpm", &img_width, &img_height);
	g->img.player.walk_left[2] = mlx_xpm_file_to_image(g->mlx, \
		"assets/player_left-3.xpm", &img_width, &img_height);
	if (!g->img.player.walk_right[0] || !g->img.player.walk_right[1] \
		|| !g->img.player.walk_right[2] || !g->img.player.walk_left[0] \
		|| !g->img.player.walk_left[1] || !g->img.player.walk_left[2])
	{
		error_message("Failed to load image");
		free_grid_and_exit(g);
	}
}

void	init_other_images(t_game *g)
{
	int		img_width;
	int		img_height;

	g->img.wall = mlx_xpm_file_to_image(g->mlx, "assets/wall-2.xpm", \
										&img_width, &img_height);
	g->img.floor = mlx_xpm_file_to_image(g->mlx, "assets/floor.xpm", \
										&img_width, &img_height);
	g->img.collectible = mlx_xpm_file_to_image(g->mlx, "assets/collectible.xpm"\
										, &img_width, &img_height);
	g->img.exit = mlx_xpm_file_to_image(g->mlx, "assets/exit-1.xpm", \
										&img_width, &img_height);
	g->img.player_win = mlx_xpm_file_to_image(g->mlx, "assets/exit-2.xpm", \
										&img_width, &img_height);
	g->img.black = mlx_xpm_file_to_image(g->mlx, "assets/black.xpm", \
										&img_width, &img_height);
	if (!g->img.wall || !g->img.floor || !g->img.collectible \
		|| !g->img.exit || !g->img.player_win || !g->img.black)
	{
		error_message("Failed to load image");
		free_grid_and_exit(g);
	}
}

void	init_images(t_game *g)
{
	init_player_up_and_down(g);
	init_player_right_and_left(g);
	init_other_images(g);
}
