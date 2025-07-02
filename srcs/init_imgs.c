/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:49:52 by cscache           #+#    #+#             */
/*   Updated: 2025/07/02 15:49:55 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		display_error_message("Failed to load image");
		clean_exit(g, EXIT_FAILURE);
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
		display_error_message("Failed to load image");
		clean_exit(g, EXIT_FAILURE);
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
		display_error_message("Failed to load image");
		clean_exit(g, EXIT_FAILURE);
	}
}

void	init_chicken_sprites(t_game *g)
{
	int		img_width;
	int		img_height;

	g->img.chicken[0] = mlx_xpm_file_to_image(g->mlx, \
		"assets/chicken-1.xpm", &img_width, &img_height);
	g->img.chicken[1] = mlx_xpm_file_to_image(g->mlx, \
		"assets/chicken-2.xpm", &img_width, &img_height);
	g->img.chicken[2] = mlx_xpm_file_to_image(g->mlx, \
		"assets/chicken-3.xpm", &img_width, &img_height);
	g->img.chicken[3] = mlx_xpm_file_to_image(g->mlx, \
		"assets/chicken-4.xpm", &img_width, &img_height);
	g->img.chicken[4] = mlx_xpm_file_to_image(g->mlx, \
		"assets/chicken-5.xpm", &img_width, &img_height);
	if (!g->img.chicken[0] || !g->img.chicken[1] \
		|| !g->img.chicken[2] || !g->img.chicken[3] \
		|| !g->img.chicken[4])
	{
		display_error_message("Failed to load image");
		clean_exit(g, EXIT_FAILURE);
	}
}

void	init_images(t_game *g)
{
	init_player_up_and_down(g);
	init_player_right_and_left(g);
	init_other_images(g);
	init_chicken_sprites(g);
}
