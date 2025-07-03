/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_create_enemy_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:45:07 by cscache           #+#    #+#             */
/*   Updated: 2025/07/03 13:54:59 by cscache          ###   ########.fr       */
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

	if (!positions || size < 1)
		return ;
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

void	place_enemies(t_game *g, t_point *positions, int size)
{
	int	i;

	if (!positions || size < 1)
		return ;
	i = 0;
	while (i < g->enemies_count && i < size)
	{
		g->enemies[i].x = positions[i].x;
		g->enemies[i].y = positions[i].y;
		i++;
	}
}
