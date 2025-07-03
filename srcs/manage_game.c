/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:39:35 by cscache           #+#    #+#             */
/*   Updated: 2025/07/03 16:03:36 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_game(t_game *g, int new_x, int new_y)
{
	(g->move_count)++;
	g->player_x = new_x;
	g->player_y = new_y;
	if (g->previous_direction == g->direction)
		g->img_index = (g->img_index + 1) % 3;
	else
		g->img_index = 0;
	if (g->game_won == 1)
		g->grid[new_y][new_x] = 'W';
	render_map(g);
	display_move_count(g);
}

int	handle_player_movement(t_game *g, int x, int y)
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
			close_window(g);
			return (0);
		}
		update_game(g, new_x, new_y);
	}
	return (1);
}

void	set_player_direction(t_game *g, int keycode)
{
	g->previous_direction = g->direction;
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

int	close_window(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	clean_exit(g, EXIT_SUCCESS);
	return (0);
}

int	handle_key_input(int keycode, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	set_player_direction(g, keycode);
	if (g->direction == QUIT)
		clean_exit(g, EXIT_SUCCESS);
	if (!g->game_won)
	{
		if (g->direction == UP)
			handle_player_movement(g, 0, -1);
		else if (g->direction == DOWN)
			handle_player_movement(g, 0, 1);
		else if (g->direction == RIGHT)
			handle_player_movement(g, 1, 0);
		else if (g->direction == LEFT)
			handle_player_movement(g, -1, 0);
		check_if_game_over(g);
	}
	return (0);
}
