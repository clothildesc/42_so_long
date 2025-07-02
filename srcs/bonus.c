/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:41:43 by cscache           #+#    #+#             */
/*   Updated: 2025/07/02 16:17:20 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	calculate_size_array_coordinates(t_game *g)
{
	int	x;
	int	y;
	int	size;

	size = 0;
	y = 0;
	while (g->grid[y])
	{
		x = 0;
		while (g->grid[y][x])
		{
			if (g->grid[y][x] == '0')
				size++;
			x++;
		}
		y++;
	}
	return (size);
}

void	fill_array_positions(t_game *g, t_point *positions)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (g->grid[y])
	{
		x = 0;
		while (g->grid[y][x])
		{
			if (g->grid[y][x] == '0')
			{
				positions[i].x = x;
				positions[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

t_point	*create_array_positions(t_game *g, int size)
{
	t_point	*positions;

	if (size == 0)
		return (NULL);
	positions = malloc(sizeof(t_point) * size);
	if (!positions)
		return (NULL);
	fill_array_positions(g, positions);
	return (positions);
}

void	shuffle_positions(t_point *positions, int size)
{
	int		i;
	int		random_index;
	t_point	temp;

	i = size - 1;
	while (i >= 0)
	{
		random_index = rand () % (i + 1);
		temp = positions[i];
		positions[i] = positions[random_index];
		positions[random_index] = temp;
		i--;
	}
}

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

void	update_position(int direction, int *new_x, int *new_y)
{
	if (direction == 0)
		(*new_y)--;
	else if (direction == 1)
		(*new_y)++;
	else if (direction == 2)
		(*new_x)--;
	else if (direction == 3)
		(*new_x)++;
}

int	is_tile_occupied(t_game *g, t_enemy *c, int new_x, int new_y)
{
	int	i;

	i = 0;
	if (g->grid[new_y][new_x] == '0')
	{
		while (i < g->enemies_count)
		{
			if (&g->enemies[i] != c && (g->enemies[i].x == new_x \
				&& g->enemies[i].y == new_y))
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

void	find_valid_direction(int *directions, t_game *g, t_enemy *c, int new_x, int new_y)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		new_x = c->x;
		new_y = c->y;
		update_position(directions[i], &new_x, &new_y);
		if (!is_tile_occupied(g, c, new_x, new_y))
		{
			c->y = new_y;
			c->x = new_x;
			c->direction = directions[i];
			break ;
		}
		i++;
	}
}

void	check_if_game_over(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->enemies_count)
	{
		if (g->enemies[i].y == g->player_y && g->enemies[i].x == g->player_x)
		{
			g->game_lose = 1;
			close_window(g);
		}
		i++;
	}
}

void	move_enemy(t_game *g, t_enemy *c)
{
	int	directions[4];
	int	new_x;
	int	new_y;
	int	i;

	new_x = c->x;
	new_y = c->y;
	i = 0;
	while (i < 4)
	{
		directions[i] = i;
		i++;
	}
	shuffle_directions(directions, 4);
	find_valid_direction(directions, g, c, new_x, new_y);
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

void	place_enemies(t_game *g, t_point *positions, int size)
{
	int	i;

	i = 0;
	while (i < g->enemies_count && i < size)
	{
		g->enemies[i].x = positions[i].x;
		g->enemies[i].y = positions[i].y;
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

void	create_enemies(t_game *g)
{
	t_point	*positions;
	int		size;

	srand(time(NULL));
	g->enemies_count = (g->width * g->height) / 50;
	size = calculate_size_array_coordinates(g);
	if (size < g->enemies_count)
		g->enemies_count = size;
	positions = create_array_positions(g, size);
	if (positions && size > 0)
	{
		shuffle_positions(positions, size);
		place_enemies(g, positions, size);
		free(positions);
	}
}

