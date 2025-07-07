/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_move_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:41:43 by cscache           #+#    #+#             */
/*   Updated: 2025/07/07 12:11:57 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_if_game_over(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->enemies_count)
	{
		if (g->enemies[i].y == g->player_y && g->enemies[i].x == g->player_x)
		{
			g->game_lose = 1;
			display_move_count(g);
			print_move_count(g);
			close_window(g);
		}
		i++;
	}
}

void	move_enemy(t_game *g, t_enemy *c)
{
	int		directions[4];
	t_point	pos;
	int		i;

	pos.x = c->x;
	pos.y = c->y;
	i = 0;
	while (i < 4)
	{
		directions[i] = i;
		i++;
	}
	shuffle_directions(directions, 4);
	find_valid_direction(directions, g, c, &pos);
}

void	move_all_enemies(t_game *g, int step)
{
	int	i;

	i = 0;
	while (i < g->enemies_count)
	{
		if (i % 2 == step)
			move_enemy(g, &g->enemies[i]);
		i++;
	}
}

int	handle_tick(t_game *g)
{
	static int		step;
	static clock_t	last_time = 0;
	clock_t			current_time;

	current_time = clock();
	if (last_time == 0)
		last_time = current_time;
	g->tick++;
	check_if_game_over(g);
	if ((current_time - last_time) >= (CLOCKS_PER_SEC * 0.4))
	{
		move_all_enemies(g, step);
		step = 1 - step;
		render_map(g);
		last_time = current_time;
	}
	return (0);
}
