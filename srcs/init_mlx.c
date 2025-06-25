/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:37:37 by cscache           #+#    #+#             */
/*   Updated: 2025/06/25 12:39:24 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_game *g)
{
	int	window_height;
	int	window_width;

	window_height = g->height * TILE_SIZE;
	window_width = g->width * TILE_SIZE;
	g->mlx = mlx_init;
	g->window = mlx_new_window(g->mlx, window_width, window_height, "so long");
}

void	init_images(t_game *g)
{
	int		img_width;
	int		img_height;

	g->img.wall = mlx_xpm_file_to_image(g->mlx, "assets/wall.xml", \
										&img_width, &img_height);
	g->img.floor = mlx_xpm_file_to_image(g->mlx, "assets/floor.xml", \
										&img_width, &img_height);
	g->img.player = mlx_xpm_file_to_image(g->mlx, "assets/player.xml", \
										&img_width, &img_height);
	g->img.collectible = mlx_xpm_file_to_image(g->mlx, "assets/collectible.xml"\
										, &img_width, &img_height);
	g->img.exit = mlx_xpm_file_to_image(g->mlx, "assets/exit.xml", \
										&img_width, &img_height);
}

void	render_map(t_game *g)
{
	char	tile;
	int		x;
	int		y;

	while (g->grid[y])
	{
		x = 0;
		while (g->grid[y][x])
		{
			tile = g->grid[y][x];
			mlx_put_image_to_window(g->mlx, g->window, g->img.floor, \
									x * TILE_SIZE, y * TILE_SIZE);
			if (tile == '1')
				mlx_put_image_to_window(g->mlx, g->window, g->img.wall, \
										x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'P')
				mlx_put_image_to_window(g->mlx, g->window, g->img.player, \
										x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'C')
				mlx_put_image_to_window(g->mlx, g->window, g->img.collectible, \
										x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'E')
				mlx_put_image_to_window(g->mlx, g->window, g->img.exit, \
										 x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	show_game(t_game *g, char *file)
{
	load_map(g, file);
	init_window(g);
	init_images(g);
	render_map(g);
	mlx_loop(g->mlx);
}
