/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_move_enemy_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:44:48 by cscache           #+#    #+#             */
/*   Updated: 2025/07/03 16:18:57 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	shuffle_directions(int *directions, int size)
{
	int		i;
	int		random_index;
	int		temp;

	i = size - 1;
	while (i >= 0)
	{
		random_index = rand () % (i + 1);
		temp = directions[i];
		directions[i] = directions[random_index];
		directions[random_index] = temp;
		i--;
	}
}

void	update_position(int direction, t_point *pos)
{
	if (direction == 0)
		pos->y--;
	else if (direction == 1)
		pos->y++;
	else if (direction == 2)
		pos->x--;
	else if (direction == 3)
		pos->x++;
}

int	is_tile_occupied(t_game *g, t_enemy *c, t_point *pos)
{
	int	i;

	i = 0;
	if (g->grid[pos->y][pos->x] != '1')
	{
		while (i < g->enemies_count)
		{
			if (&g->enemies[i] != c && (g->enemies[i].x == pos->x \
				&& g->enemies[i].y == pos->y))
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

void	find_valid_direction(int *directions, t_game *g, t_enemy *c, \
	t_point *pos)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		pos->x = c->x;
		pos->y = c->y;
		update_position(directions[i], pos);
		if (!is_tile_occupied(g, c, pos))
		{
			c->y = pos->y;
			c->x = pos->x;
			c->direction = directions[i];
			break ;
		}
		i++;
	}
}
