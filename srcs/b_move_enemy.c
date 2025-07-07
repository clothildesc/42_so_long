/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_move_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:41:43 by cscache           #+#    #+#             */
/*   Updated: 2025/07/07 10:01:00 by cscache          ###   ########.fr       */
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
	static int	step;

	g->tick++;
	check_if_game_over(g);
	if (g->tick % 60000 == 0)
	{
		move_all_enemies(g, step);
		step = 1 - step;
		render_map(g);
	}
	return (0);
}
