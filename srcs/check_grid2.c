/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscache <cscache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:57:37 by cscache           #+#    #+#             */
/*   Updated: 2025/06/24 16:57:59 by cscache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_counters(t_game *g, char c, int x, int y)
{
	if (c == 'P')
	{
		(g->player_count)++;
		g->player_x = x;
		g->player_y = y;
	}
	else if (c == 'C')
		(g->collectibles)++;
	else if (c == 'E')
		(g->exit_count)++;
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
				return (ft_putendl_fd("Error: element is not allowed\n", 2), 0);
			init_counters(g, g->grid[y][x], x, y);
			x++;
		}
		y++;
	}
	return (check_rules_for_elements(g));
}

void	validate_map(t_game *g)
{
	if (!g->grid)
		ft_putendl_fd("Error: map does not exist\n", 2);
	if (!init_width_and_check_rectangularity(g))
		ft_putendl_fd("Error: map is not rectangular\n", 2);
	if (!check_walls(g))
		ft_putendl_fd("Error: map is not surronded by walls\n", 2);
	if (!check_elements(g))
		ft_putendl_fd("Error: map must contain valid elements\n", 2);
	else
	{
		ft_printf("MAP IS VALID\n");
		return ;
	}
	free_grid(g);
	exit(EXIT_FAILURE);
}
