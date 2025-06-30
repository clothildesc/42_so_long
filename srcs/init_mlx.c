/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:37:37 by cscache           #+#    #+#             */
/*   Updated: 2025/06/30 14:52:12 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	paint_black_move_zone(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->width * TILE_SIZE)
	{
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.black, \
								i, g->height * TILE_SIZE);
		i += TILE_SIZE;
	}
}

void	diplay_images(t_game *g, int x, int y, char tile)
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

void	display_player(t_game *g)
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
			diplay_images(g, x, y, tile);
			x++;
		}
		y++;
	}
	if (!g->game_won)
		display_player(g);
	paint_black_move_zone(g);
}

void	show_total_count(t_game *g)
{
	char	*str;

	str = ft_itoa(g->move_count);
	if (!g->game_won)
	{
		mlx_string_put(g->mlx, g->mlx_win, 15, (g->height * TILE_SIZE) + 20, \
		0xFFFFFF, "Total moves: ");
		mlx_string_put(g->mlx, g->mlx_win, 100, (g->height * TILE_SIZE) + 20, \
		0xFFFFFF, str);
	}
	else
	{
		mlx_string_put(g->mlx, g->mlx_win, 15, (g->height * TILE_SIZE) + 20, \
		0xFFFFFF, "CONGRATS! Total move : ");
		mlx_string_put(g->mlx, g->mlx_win, 160, (g->height * TILE_SIZE) + 20, \
		0xFFFFFF, str);
	}
	free(str);
}

void	update_game(t_game *g, int new_x, int new_y)
{
	(g->move_count)++;
	g->player_x = new_x;
	g->player_y = new_y;
	g->img_index = (g->img_index + 1) % 3;
	if (g->game_won == 1)
		g->grid[new_y][new_x] = 'W';
	render_map(g);
	show_total_count(g);
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
		if (g->grid[new_y][new_x] == 'C')
		{
			g->collectibles--;
			g->grid[new_y][new_x] = '0';
		}
		else if (g->grid[new_y][new_x] == 'E' && g->collectibles == 0)
		{
			g->game_won = 1;
			update_game(g, new_x, new_y);
			return (0);
		}
		update_game(g, new_x, new_y);
	}
	return (1);
}
void	define_direction(t_game *g, int keycode)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		g->direction = UP;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		g->direction = DOWN;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		g->direction = RIGHT;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		g->direction = LEFT;
	else if (keycode == KEY_ESC || keycode == KEY_Q)
		g->direction = QUIT;
}

int	key_handler(int keycode, void *param)
{
	t_game	*g;

	g = (t_game *)param;

	define_direction(g, keycode);
	if (g->direction == QUIT)
	{
		mlx_destroy_window(g->mlx, g->mlx_win);
		free_grid_and_exit(g);
	}
	if (!g->game_won)
	{
		if (g->direction == UP)
			move_player(g, 0, -1);
		else if (g->direction == DOWN)
			move_player(g, 0, 1);
		else if (g->direction == RIGHT)
			move_player(g, 1, 0);
		else if (g->direction == LEFT)
			move_player(g, -1, 0);
	}
	return (0);
}

void	show_game(t_game *g, char *file)
{
	if (load_map(g, file))
	{
		init_window(g);
		init_images(g);
		render_map(g);
		show_total_count(g);
		mlx_key_hook(g->mlx_win, key_handler, g);
		mlx_loop(g->mlx);
	}
}
