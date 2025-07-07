/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_create_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:20:13 by cscache           #+#    #+#             */
/*   Updated: 2025/07/07 11:45:18 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_conditions_to_create(t_game *g, t_point *positions, int size)
{
	if (positions && g->height > 4 && g->width > 4 && size > 4 && \
		g->enemies_count > 0)
		return (1);
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
	if (valid_conditions_to_create(g, positions, size))
	{
		shuffle_positions(positions, size);
		place_enemies(g, positions, size);
	}
	else
		g->enemies_count = 0;
	if (positions)
		free(positions);
}
