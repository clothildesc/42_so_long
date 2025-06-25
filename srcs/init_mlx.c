/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:37:37 by cscache           #+#    #+#             */
/*   Updated: 2025/06/25 17:29:35 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_game *g)
{
	int	window_height;
	int	window_width;

	window_height = g->height * TILE_SIZE;
	window_width = g->width * TILE_SIZE;
	g->mlx = mlx_init();
	if (!g->mlx)
	{
		ft_putendl_fd("Error: Failed to initialize MLX", 2);
		free_grid_and_exit(g);
	}
	g->mlx_win = mlx_new_window(g->mlx, window_width, window_height, "so long");
	if (!g->mlx_win)
	{
		ft_putendl_fd("Error: Failed to  open window", 2);
		free_grid_and_exit(g);
	}
}

void	init_images(t_game *g)
{
	int		img_width;
	int		img_height;

	g->img.wall = mlx_xpm_file_to_image(g->mlx, "assets/wall-2.xpm", \
										&img_width, &img_height);
	g->img.floor = mlx_xpm_file_to_image(g->mlx, "assets/floor.xpm", \
										&img_width, &img_height);
	g->img.player = mlx_xpm_file_to_image(g->mlx, "assets/player.xpm", \
										&img_width, &img_height);
	g->img.collectible = mlx_xpm_file_to_image(g->mlx, "assets/collectible.xpm"\
										, &img_width, &img_height);
	g->img.exit = mlx_xpm_file_to_image(g->mlx, "assets/exit-1.xpm", \
										&img_width, &img_height);
	g->img.player_win = mlx_xpm_file_to_image(g->mlx, "assets/player_win.xpm", \
										&img_width, &img_height);
	if (!g->img.wall || !g->img.floor || !g->img.player || !g->img.collectible \
		|| !g->img.exit || !g->img.player_win)
	{
		ft_putendl_fd("Error: Failed to load imahe", 2);
		free_grid_and_exit(g);
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
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.player, \
							g->player_x * TILE_SIZE, g->player_y * TILE_SIZE);
}

int	move_player(t_game *g, int x, int y)
{
	int		new_x;
	int		new_y;

	new_x = g->player_x + x;
	new_y = g->player_y + y;
	if (new_x < 0 || new_y < 0 || new_x >= g->width || new_y >= g->height)
		return (0);
	if (g->grid[new_y][new_x] == '0' || g->grid[new_y][new_x] == 'C' || \
		g->grid[new_y][new_x] == 'E')
	{
		if (g->grid[new_y][new_x] == 'E' && g->collectibles == 0)
		{
			g->player_x = new_x;
			g->player_y = new_y;
			mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.player_win, \
										new_x * TILE_SIZE, new_x * TILE_SIZE);
			(g->move_count)++;
			render_map(g);
			ft_printf("VICTOIRE");
			return (1);
		}
		if (g->grid[new_y][new_x] == 'C')
		{
			g->collectibles -= 1;
			g->grid[new_y][new_x] = '0';
		}
		(g->move_count)++;
		g->player_x = new_x;
		g->player_y = new_y;
	}
	render_map(g);
	ft_printf("Total moves = %d\n", g->move_count);
	return (1);
}

int	key_handler(int keycode, void *param)
{
	t_game	*g;

	g = (t_game *)param;

	if (keycode == KEY_UP)
		move_player(g, 0, -1);
	else if (keycode == KEY_DOWN)
		move_player(g, 0, 1);
	else if (keycode == KEY_RIGHT)
		move_player(g, 1, 0);
	else if (keycode == KEY_LEFT)
		move_player(g, -1, 0);
	return (0);
}

void	show_game(t_game *g, char *file)
{
	if (load_map(g, file))
	{
		init_window(g);
		init_images(g);
		render_map(g);
		mlx_key_hook(g->mlx_win, key_handler, g);
		mlx_loop(g->mlx);
	}
}
