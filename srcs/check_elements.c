/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:53:14 by cscache           #+#    #+#             */
/*   Updated: 2025/07/01 11:55:31 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_in_dataset(char c)
{
	char	*dataset;
	int		i;

	dataset = "PEC01";
	i = 0;
	while (dataset[i])
	{
		if (c == dataset[i])
			return (1);
		i++;
	}
	return (0);
}

void	init_counters(t_game *g, char c, int x, int y)
{
	if (c == 'P')
	{
		(g->player_count)++;
		g->player_x = x;
		g->player_y = y;
		g->grid[y][x] = '0';
	}
	else if (c == 'C')
		(g->collectibles)++;
	else if (c == 'E')
		(g->exit_count)++;
}

int	check_rules_for_elements(t_game *g)
{
	if (g->player_count != 1)
		return \
		(display_error_message("Map must contain exactly one player"), 0);
	else if (g->exit_count != 1)
		return (display_error_message("Map must contain exactly one exit"), 0);
	else if (g->collectibles < 1)
		return \
		(display_error_message("Map must contain at least one collectible"), 0);
	return (1);
}

int	check_elements(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (g->grid[y])
	{
		x = 0;
		while (g->grid[y][x])
		{
			if (!is_in_dataset(g->grid[y][x]))
				return (display_error_message("Element is not allowed"), 0);
			init_counters(g, g->grid[y][x], x, y);
			x++;
		}
		y++;
	}
	return (check_rules_for_elements(g));
}
