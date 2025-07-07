/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:36:13 by cscache           #+#    #+#             */
/*   Updated: 2025/07/07 10:35:26 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_tiles_images(t_game *g, int x, int y, char tile)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.floor, \
							x * TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.wall, \
								x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.collectible, \
								x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.exit, \
								x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'W')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.player_win, \
								x * TILE_SIZE, y * TILE_SIZE);
}

void	render_player_sprites(t_game *g)
{
	if (g->direction == DOWN)
		mlx_put_image_to_window(g->mlx, g->mlx_win, \
						g->img.player.walk_down[g->img_index], \
						g->player_x * TILE_SIZE, g->player_y * TILE_SIZE);
	else if (g->direction == UP)
		mlx_put_image_to_window(g->mlx, g->mlx_win, \
						g->img.player.walk_up[g->img_index], \
						g->player_x * TILE_SIZE, g->player_y * TILE_SIZE);
	else if (g->direction == RIGHT)
		mlx_put_image_to_window(g->mlx, g->mlx_win, \
						g->img.player.walk_right[g->img_index], \
						g->player_x * TILE_SIZE, g->player_y * TILE_SIZE);
	else if (g->direction == LEFT)
		mlx_put_image_to_window(g->mlx, g->mlx_win, \
						g->img.player.walk_left[g->img_index], \
						g->player_x * TILE_SIZE, g->player_y * TILE_SIZE);
	else
		mlx_put_image_to_window(g->mlx, g->mlx_win, \
						g->img.player.walk_down[0], \
						g->player_x * TILE_SIZE, g->player_y * TILE_SIZE);
}

void	render_enemies(t_game *g)
{
	int	i;
	int	frame;

	frame = (g->tick / 10000) % 5;
	i = 0;
	while (i < g->enemies_count)
	{
		mlx_put_image_to_window(g->mlx, g->mlx_win, \
								g->img.chicken[frame], \
								g->enemies[i].x * TILE_SIZE, \
								g->enemies[i].y * TILE_SIZE);
		i++;
	}
}

void	render_map(t_game *g)
{
	char	tile;
	int		x;
	int		y;

	y = 0;
	while (g->grid[y])
	{
		x = 0;
		while (g->grid[y][x])
		{
			tile = g->grid[y][x];
			render_tiles_images(g, x, y, tile);
			x++;
		}
		y++;
	}
	if (!g->game_won)
	{
		render_player_sprites(g);
		render_enemies(g);
	}
	draw_black_move_zone(g);
	display_move_count(g);
}
